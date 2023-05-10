NAME					= SimpleNavigator

## Использовать, когда понадобится библиотека для UI
# LIB_DIR					= lib

MATRIX_LIB				= $(LIB_DIR)/matrix.a

APP_DIR					= app
APP_HEADERS_DIR			= $(APP_DIR)/includes
APP_INCLUDES			= -I$(APP_HEADERS_DIR)
APP_SRCS				= $(shell find $(APP_DIR) -name "*.cpp")
APP_OBJS				= $(patsubst %.cpp, %.o, $(APP_SRCS))
APP_D_FILES				= ${patsubst %.cpp, %.d, ${APP_SRCS}}

## matrix.h static library sources
MATRIX_DIR				= graph
MATRIX_HEADERS_DIR		= $(MATRIX_DIR)/includes
MATRIX_INTERFACES_DIR	= $(MATRIX_DIR)/interfaces
MATRIX_INCLUDES			= -I$(MATRIX_HEADERS_DIR) -I$(MATRIX_INTERFACES_DIR)
MATRIX_SRCS				:= $(shell find $(MATRIX_DIR) -name "*.cpp")
MATRIX_OBJS				= $(patsubst %.cpp, %.o, $(MATRIX_SRCS))
MATRIX_D_FILES			= ${patsubst %.cpp, %.d, ${MATRIX_SRCS}}

CXX				= c++
CXXFLAGS		= -Werror -Wall -Wextra -std=c++17
AR				= ar -rcs

all:	$(NAME)

leaks:
		$(CXXFLAGS) += -fsanitize=address,undefined -fno-sanitize-recover -fstack-protector -O0
		$(MAKE) run_leaks

## Использовать, когда понадобится библиотека для UI
# $(LIB_DIR):
# 		mkdir $(LIB_DIR)

libs: $(MATRIX_LIB)

$(MATRIX_DIR)/%.o: $(MATRIX_DIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c $(MATRIX_INCLUDES) $< -o $@ -MMD

$(MATRIX_LIB): $(MATRIX_OBJS)
		$(AR) $(MATRIX_LIB) $(MATRIX_OBJS)


$(NAME): $(MATRIX_LIB) $(APP_SRCS)
		$(CXX) $(CXXFLAGS) $(APP_SRCS) $(APP_INCLUDES) \
		-o $(NAME)

clean:
		@rm -f $(MATRIX_OBJS) $(APP_OBJS) \
		$(APP_D_FILES) $(MATRIX_D_FILES) $(MATRIX_LIB) \

fclean: clean
		@rm -rf $(NAME) $(LIB_DIR) $(STACK_LIB) $(QUEUE_LIB)

re:		fclean all

run_leaks : $(NAME)
	leaks --atExit -- ./$(NAME)

test:
	cd ../tests && ${MAKE}

include $(wildcard $(APP_D_FILES) $(MATRIX_D_FILES))

.PHONY: all clean test fclean re $(MATRIX_LIB)
