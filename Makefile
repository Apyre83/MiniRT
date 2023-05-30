MY_SOURCES =	srcs/main.c \
				srcs/color.c \
				srcs/math_basic.c \
				srcs/math_vector.c \
				srcs/debug.c \
				srcs/mlx_custom.c \
				srcs/parsing.c \
				srcs/vector.c \
				srcs/event.c \
				srcs/get_all.c \
				srcs/cylinder.c \
				srcs/sphere.c \
				srcs/vector_utils.c \
				srcs/math_utils.c \
				srcs/parsing_utils_1.c \
				srcs/parsing_utils_2.c \
				srcs/parsing_utils_3.c \
				srcs/parsing_utils_4.c \
				srcs/parsing_utils_5.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

INCLUDES = includes/

LIBFT = libft/libft.a
LIBMLX = minilibx/libmlx.a

FLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

NAME = miniRT

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	@make -C libft/
	@make -C minilibx
	@clear
	@gcc $(FLAGS) $(MY_OBJECTS) $(LIBFT) $(LIBMLX) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[32;5m ██████╗ ██████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗     ██╗"
	@echo "██╔════╝██╔═══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗    ██║"
	@echo "██║     ██║   ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║    ██║"
	@echo "██║     ██║   ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║    ╚═╝"
	@echo "╚██████╗╚██████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝    ██╗"
	@echo " ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝     ╚═╝\033[0m"

clean:
	@rm -f $(MY_OBJECTS)
	@make clean -C libft/
	@make clean -C minilibx/
	@echo "\033[0;92m.o files cleaned.\033[0;39m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@make clean -C libft/
	@make clean -C minilibx/
	@echo "\033[0;92mEverything cleaned.\033[0;39m"

re: fclean all

.PHONY: all clean fclean re
