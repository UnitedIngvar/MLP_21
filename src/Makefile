NAME					= MLP

## Использовать, когда понадобится библиотека для UI
# LIB_DIR					= lib

SRC_DIR					= .
SRC_HEADER_DIRS			= $(shell find $(SRC_DIR) -type d -name "include*")
SRC_INCLUDES			= $(addprefix -I, $(SRC_HEADER_DIRS))
SRC_SRCS				= $(shell find $(SRC_DIR) -name "*.cc")
SRC_OBJS				= $(patsubst %.cc, %.o, $(SRC_SRCS))
SRC_D_FILES				= ${patsubst %.cc, %.d, ${SRC_SRCS}}

CXX				= c++
CXXFLAGS		= -Werror -Wall -Wextra -std=c++17
AR				= ar -rcs

CXX				= g++
CXXFLAGS		= -Werror -Wall -Wextra -std=c++17

all:	$(NAME)

leaks:
		$(CXXFLAGS) += -fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -O0
		$(MAKE) run_leaks

## all, install, uninstall, clean, dvi, dist

$(NAME): $(SRC_OBJS)
		$(CXX) $(CXXFLAGS) $(SRC_OBJS) -o $(NAME)

%.o: %.cc
		$(CXX) $(CXXFLAGS) -c $(SRC_INCLUDES) $< -o $@ -MMD

clean:
		@rm -f $(SRC_OBJS) $(SRC_D_FILES)

fclean: clean
		@rm -rf $(NAME)

re:		fclean all

run_leaks : $(NAME)
	leaks --atExit -- ./$(NAME)

include $(wildcard $(SRC_D_FILES))

.PHONY: all clean test fclean re