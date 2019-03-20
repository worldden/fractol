#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 12:43:43 by ddehtyar          #+#    #+#              #
#    Updated: 2018/07/04 17:40:20 by ddehtyar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

HEAD = fractol.h

FL	=  -Wall -Werror -Wextra 

SRC = main.c hook.c threds.c zoom.c help_fract.c fractol.c fractol_two.c fractol_help.c col_image.c

OBJ = $(SRC:.c=.o)

LIB     =./libft/libft.a

FLGMLX     = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft
	gcc $(FL) -I $(HEAD) -c $(SRC)
	gcc $(FL) -o $(NAME) $(OBJ) $(LIB) $(FLGMLX)

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
