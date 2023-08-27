# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 11:22:25 by tidurand          #+#    #+#              #
#    Updated: 2022/05/04 11:05:40 by tidurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/main.c \
			./srcs/hooks.c \
			./srcs/draw.c \
			./srcs/light.c \
			./srcs/intersections/sphere.c \
			./srcs/intersections/plan.c \
			./srcs/intersections/cylinder.c \
			./srcs/intersections/cylinder_form.c \
			./srcs/utils/vector1.c \
			./srcs/utils/vector2.c \
			./srcs/utils/vector_rot.c \
			./srcs/utils/free.c \
			./srcs/parser.c \
			./srcs/checker.c \
			./srcs/struct_maker.c \
			./srcs/struct_maker2.c \
			./srcs/shadow.c \
			./srcs/shadow2.c \
			./srcs/checks_obj1.c \
			./srcs/checks_obj2.c


OBJS	= $(SRCS:.c=.o)

CC		= clang
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -g3

NAME	= miniRT

PATH_MLX	=./mlx

LINUX	= -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz -L./libft -lft

%.o: %.c ./incs/miniRT.h ./incs/types.h
		$(CC) $(CFLAGS) -I /usr/include -Imlx_linux -Ilibft -O3 -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJS) 
		make -C $(PATH_MLX) all
		make -C ./libft all
		$(CC) $(CFLAGS) $(OBJS) mlx/libmlx_Linux.a $(LINUX) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		make -C $(PATH_MLX) clean
		make -C ./libft clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
