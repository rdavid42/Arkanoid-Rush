
SRC_PATH	=	src/

OBJ_PATH	=	obj/
INC_PATH	=	inc/

SRCS		=	$(shell ls $(SRC_PATH) | grep .c$$)
OBJS		=	$(patsubst %.c, $(OBJ_PATH)%.o,$(SRCS))

PLATFORM	:=	$(shell uname)
CC			=	gcc
HEADER		=	-I./$(INC_PATH) -I./glfw/include
FLAGS		=	-Ofast -g -Wall -Wextra -Werror
VARS		=	-DDEBUG

LIBS		=	./glfw/src/libglfw3.a -lGL -lXrandr -lXi -lXrender -ldrm -lXdamage -lXxf86vm -lXext -lX11 -lpthread -lXcursor -lm -lXinerama

NAME		=	arkanoid

all: $(NAME)

$(NAME): $(OBJS)
	@cmake glfw/CMakeLists.txt
	@make -C glfw/
	@$(CC) $(FLAGS) $(VARS) $(HEADER) -o $(NAME) $(OBJS) $(LIBS)

$(patsubst %, $(OBJ_PATH)%,%.o): $(SRC_PATH)$(notdir %.c)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(VARS) $(HEADER) "$<" -o "$@"

clean:
	@make -C glfw/ clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

l: re
	@./$(NAME)

launch: l

.PHONY: clean fclean re
