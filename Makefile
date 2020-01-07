#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbratsla <tbratsla@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 11:59:25 by tbratsla          #+#    #+#              #
#    Updated: 2019/03/11 11:59:26 by tbratsla         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fractol

SRC	= 	src/main.c \
		src/mouse_key.c \
		src/flow.c \
		src/keys.c \
		src/calc_fract.c \
 		src/valid.c 

OBJ     = $(SRC:.c=.o)
LIBFT   = Libft/
HDR  = inc/frac.h 
CC      = /usr/bin/gcc
CFLAGS  = -Wall -Wextra -Werror
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all:        $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	make -o2 -C $(LIBFT)	
	$(CC) -o2 $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT) -lft $(FMLX)

%.o : %.c $(HDR) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	make fclean -C $(LIBFT)
	$(DEL) $(OBJ)

fclean:     clean
	make -C $(LIBFT) fclean
	$(DEL) $(NAME)


re:     fclean all

.PHONY:     re all clean fclean

	