:X
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboualla <eboualla@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 18:36:33 by eboualla          #+#    #+#              #
#    Updated: 2026/05/11 21:11:52 by eboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = ft_printf.c \
	  ft_putchar.c \
	  handle_i.c \
	  handle_p.c \
	  handle_s.c \
	  handle_x.c \
	  handle_u.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
