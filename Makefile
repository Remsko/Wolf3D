NAME = wolf3d

CC = gcc
RM = rm -rf
CFLAGS = -Werror -Wall -Wextra

LIBFT = libft/libft.a

SRC_PATH = srcs/
SRC_NAME = main.c \
			sdl_init.c \
			sdl_destroy.c \
			sdl_loop.c \
			sdl_draw.c \
			sdl_event.c \
			sdl_fps.c \
			wolf3d_draw.c \
			wolf3d_actions.c \
			wolf3d_parser.c \
			wolf3d_garbage.c \

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CPPFLAGS = -Iincs \
		   -Ilibft \
		   -I ~/.brew/include/SDL2 \

LDFLAGS = -Llibft \
		  -L ~/.brew/lib \

LDLIBS = -lft \
		 -lSDL2 \

all: $(NAME)

$(LIBFT):
	make -C libft

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
