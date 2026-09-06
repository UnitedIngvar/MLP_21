CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
INCLUDES = \
	-I../src/model/neural_network/includes \
	-I../src/model/matrix/includes \
	-I../src/model/proto/includes \
	-I../src/model/app/includes \
	-I../src/model/picture/includes \
	-I../src/model/utils/includes

PROTOBUF_CFLAGS := $(shell pkg-config --cflags protobuf 2>/dev/null)
PROTOBUF_LIBS := $(shell pkg-config --libs protobuf 2>/dev/null)
ifeq ($(PROTOBUF_LIBS),)
PROTOBUF_LIBS = -lprotobuf
endif

SRCS = \
	test_training.cc \
	../src/model/neural_network/neural_network.cc \
	../src/model/neural_network/neural_network_builder.cc \
	../src/model/matrix/matrix.cc \
	../src/model/proto/neural_network.pb.cc \
	../src/model/app/mlp.cc \
	../src/model/app/metrics_aggregator.cc \
	../src/model/picture/picture.cc \
	../src/model/picture/train_picture_reader.cc \
	../src/model/picture/picture_shifter.cc \
	../src/model/picture/picture_normalizer.cc \
	../src/model/picture/picture_scaler.cc \
	../src/model/picture/bmp_reader.cc \
	../src/model/utils/timer.cc

all: test_training
	./test_training

test_training: $(SRCS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(PROTOBUF_CFLAGS) $(SRCS) -o $@ $(PROTOBUF_LIBS)

clean:
	rm -f test_training

.PHONY: all clean
