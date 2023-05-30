UP = "\033[A"
CLEAR = "\033[K"

MY_SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_char.c ft_hex_low.c \
	ft_hex_low_2.c ft_hex_upp.c ft_hex_upp_2.c ft_int.c ft_int_2.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_options.c \
	ft_options_2.c ft_percent.c ft_ptr.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_str.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c ft_unsigned.c ft_utils.c \
	ft_utils_2.c get_next_line_bonus.c get_next_line_utils_bonus.c ftprintf.c

MY_OBJECTS =  $(MY_SOURCES:.c=.o)

INCLUDES = ./

FLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

NAME = libft.a

all: $(NAME)

.c.o:
	@gcc $(FLAGS) -c $< -o $(<:.c=.o)
	@echo $(UP)"\033[0;93mCompiling Libft : $@ \033[0;39m                                    "

$(NAME): $(MY_OBJECTS)
	@ar rcs $(NAME) $(MY_OBJECTS)
	@echo $(UP)"\033[0;92mLibft compiled !\033[0;39m                                    "

clean:
	@rm -f $(MY_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
