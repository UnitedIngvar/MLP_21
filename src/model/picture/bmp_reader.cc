#include "bmp_reader.h"

#include <fstream>
#include <iostream>

using namespace s21;
using namespace std;

Picture BmpReader::ReadPictureToBlackAndWhite(std::ifstream &filestream) {
  // заголовк изображения
  BITMAPFILEHEADER fileHeader;
  Read(filestream, fileHeader.bfType, sizeof(fileHeader.bfType));
  Read(filestream, fileHeader.bfSize, sizeof(fileHeader.bfSize));
  Read(filestream, fileHeader.bfReserved1, sizeof(fileHeader.bfReserved1));
  Read(filestream, fileHeader.bfReserved2, sizeof(fileHeader.bfReserved2));
  Read(filestream, fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));

  if (fileHeader.bfType != 0x4D42) {
    throw std::invalid_argument("not a bmp file");
  }

  // информация изображения
  BITMAPINFOHEADER fileInfoHeader;
  Read(filestream, fileInfoHeader.biSize, sizeof(fileInfoHeader.biSize));

  // bmp core
  if (fileInfoHeader.biSize >= 12) {
    Read(filestream, fileInfoHeader.biWidth, sizeof(fileInfoHeader.biWidth));
    Read(filestream, fileInfoHeader.biHeight, sizeof(fileInfoHeader.biHeight));
    Read(filestream, fileInfoHeader.biPlanes, sizeof(fileInfoHeader.biPlanes));
    Read(filestream, fileInfoHeader.biBitCount,
         sizeof(fileInfoHeader.biBitCount));
  }

  // получаем информацию о битности
  int colorsCount = fileInfoHeader.biBitCount >> 3;
  if (colorsCount < 3) {
    colorsCount = 3;
  }

  int bitsOnColor = fileInfoHeader.biBitCount / colorsCount;
  int maskValue = (1 << bitsOnColor) - 1;

  // bmp v1
  if (fileInfoHeader.biSize >= 40) {
    Read(filestream, fileInfoHeader.biCompression,
         sizeof(fileInfoHeader.biCompression));
    Read(filestream, fileInfoHeader.biSizeImage,
         sizeof(fileInfoHeader.biSizeImage));
    Read(filestream, fileInfoHeader.biXPelsPerMeter,
         sizeof(fileInfoHeader.biXPelsPerMeter));
    Read(filestream, fileInfoHeader.biYPelsPerMeter,
         sizeof(fileInfoHeader.biYPelsPerMeter));
    Read(filestream, fileInfoHeader.biClrUsed,
         sizeof(fileInfoHeader.biClrUsed));
    Read(filestream, fileInfoHeader.biClrImportant,
         sizeof(fileInfoHeader.biClrImportant));
  }

  // bmp v2
  fileInfoHeader.biRedMask = 0;
  fileInfoHeader.biGreenMask = 0;
  fileInfoHeader.biBlueMask = 0;

  if (fileInfoHeader.biSize >= 52) {
    Read(filestream, fileInfoHeader.biRedMask,
         sizeof(fileInfoHeader.biRedMask));
    Read(filestream, fileInfoHeader.biGreenMask,
         sizeof(fileInfoHeader.biGreenMask));
    Read(filestream, fileInfoHeader.biBlueMask,
         sizeof(fileInfoHeader.biBlueMask));
  }

  // если маска не задана, то ставим маску по умолчанию
  if (fileInfoHeader.biRedMask == 0 || fileInfoHeader.biGreenMask == 0 ||
      fileInfoHeader.biBlueMask == 0) {
    fileInfoHeader.biRedMask = maskValue << (bitsOnColor * 2);
    fileInfoHeader.biGreenMask = maskValue << bitsOnColor;
    fileInfoHeader.biBlueMask = maskValue;
  }

  // bmp v3
  if (fileInfoHeader.biSize >= 56) {
    Read(filestream, fileInfoHeader.biAlphaMask,
         sizeof(fileInfoHeader.biAlphaMask));
  } else {
    fileInfoHeader.biAlphaMask = maskValue << (bitsOnColor * 3);
  }

  // bmp v4
  if (fileInfoHeader.biSize >= 108) {
    Read(filestream, fileInfoHeader.biCSType, sizeof(fileInfoHeader.biCSType));
    Read(filestream, fileInfoHeader.biEndpoints,
         sizeof(fileInfoHeader.biEndpoints));
    Read(filestream, fileInfoHeader.biGammaRed,
         sizeof(fileInfoHeader.biGammaRed));
    Read(filestream, fileInfoHeader.biGammaGreen,
         sizeof(fileInfoHeader.biGammaGreen));
    Read(filestream, fileInfoHeader.biGammaBlue,
         sizeof(fileInfoHeader.biGammaBlue));
  }

  // bmp v5
  if (fileInfoHeader.biSize >= 124) {
    Read(filestream, fileInfoHeader.biIntent, sizeof(fileInfoHeader.biIntent));
    Read(filestream, fileInfoHeader.biProfileData,
         sizeof(fileInfoHeader.biProfileData));
    Read(filestream, fileInfoHeader.biProfileSize,
         sizeof(fileInfoHeader.biProfileSize));
    Read(filestream, fileInfoHeader.biReserved,
         sizeof(fileInfoHeader.biReserved));
  }

  // проверка на поддерку этой версии формата
  if (fileInfoHeader.biSize != 12 && fileInfoHeader.biSize != 40 &&
      fileInfoHeader.biSize != 52 && fileInfoHeader.biSize != 56 &&
      fileInfoHeader.biSize != 108 && fileInfoHeader.biSize != 124) {
    throw std::invalid_argument("Unsupported BMP format");
  }

  if (fileInfoHeader.biBitCount != 16 && fileInfoHeader.biBitCount != 24 &&
      fileInfoHeader.biBitCount != 32) {
    throw std::invalid_argument("Unsupported BMP bit count");
  }

  if (fileInfoHeader.biCompression != 0 && fileInfoHeader.biCompression != 3) {
    throw std::invalid_argument("Unsupported BMP compression.");
  }

  // определение размера отступа в конце каждой строки
  int linePadding =
      ((fileInfoHeader.biWidth * (fileInfoHeader.biBitCount / 8)) % 4) & 3;

  // чтение
  unsigned int bufer;
  vector<vector<pixel>> resultMap(fileInfoHeader.biHeight);
  for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
    resultMap[i] = vector<pixel>(fileInfoHeader.biWidth);

    for (unsigned int j = 0; j < fileInfoHeader.biWidth; j++) {
      Read(filestream, bufer, fileInfoHeader.biBitCount / 8);

      pixel rgbRed = Bitextract(bufer, fileInfoHeader.biRedMask);
      pixel rgbGreen = Bitextract(bufer, fileInfoHeader.biGreenMask);
      pixel rgbBlue = Bitextract(bufer, fileInfoHeader.biBlueMask);

      unsigned char avg = (rgbRed + rgbGreen + rgbBlue) / 3;
      if (avg >= 210) {
        resultMap[i][j] = 0;
      } else if (avg < 210 && avg >= 80) {
        resultMap[i][j] = 128;
      } else {
        resultMap[i][j] = 255;
      }
      filestream.seekg(linePadding, std::ios_base::cur);
    }

    return Picture(resultMap);
  }
}

pixel BmpReader::Bitextract(const unsigned int byte, const unsigned int mask) {
  if (mask == 0) {
    return 0;
  }

  // определение количества нулевых бит справа от маски
  int maskBufer = mask, maskPadding = 0;

  while (!(maskBufer & 1)) {
    maskBufer >>= 1;
    maskPadding++;
  }

  // применение маски и смещение
  return (byte & mask) >> maskPadding;
}