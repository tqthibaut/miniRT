NAME	=	libft.a

SRCS	=	ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c ft_putchar_fd.c ft_strlcat.c ft_substr.c \
				ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c \
				ft_strlen.c	ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c	ft_strmapi.c ft_isalnum.c ft_memcmp.c \
				ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strnstr.c ft_isascii.c ft_memmove.c \
				ft_strdup.c ft_strrchr.c ft_split_plus.c ft_free_tabs.c get_next_line.c get_next_line_utils.c ft_strjoin_plus.c\
				ft_split_tab.c ft_isadouble.c ft_atof.c ft_atodb.c\

OBJ		=	$(SRCS:.c=.o)

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o	:	$(CC) $(CFLAGS) -c $< -o $(<:.c = .o)

$(NAME)	:	$(OBJ)
				ar rcs $(NAME) $(OBJ)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all
