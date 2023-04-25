# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2023/04/25 16:48:03 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
PRINTF_PATH = ./printf
PRINTF = $(PRINTF_PATH)
SRC = solong.c set_img.c read_map.c get_map_info.c key.c keys_2.c check.c itoa.c
OBJ		= 	$(SRC:.c=.o)
CC = gcc
CFLAGS = -Werror -Wall -Wextra
MLX				=	./libmlx.dylib
CFLAGS			=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -Imlx -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJ)
	make -C $(PRINTF_PATH)
	$(CC) $(OBJ) $(PRINTF)/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ${PRINTF_PATH}
	rm -rf ${OBJ}

fclean:			clean
	make fclean -C ${PRINTF_PATH}
	rm -rf ${NAME}

re:				fclean all
