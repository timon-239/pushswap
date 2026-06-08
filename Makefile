# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/05/14 14:32:48 by tireis           #+#    #+#               #
#    Updated: 2026/06/08 14:04:41 by tireis          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c \
          utils.c \
          op_swap.c \
          op_push.c \
          op_rotate.c \
          op_reverse.c \
          sort_simple.c \
          sort_medium.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
