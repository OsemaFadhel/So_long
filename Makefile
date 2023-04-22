# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2023/04/22 17:40:48 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
SRC = solong.c set_img.c read_map.c get_map_info.c key.c movement.c check.c
OBJ		= 	$(SRC:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra
MLX				=	./libmlx.dylib
CFLAGS			=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -Imlx -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf *.o

fclean:			clean

re:				fclean all