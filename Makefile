# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                          :+:      :+:    :+:     #
#                                                    +:+ +:+         +:+       #
#    By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/05/14 14:32:48 by tireis           #+#    #+#               #
#    Updated: 2026/06/16 12:53:37 by tireis          ###   ########.fr         #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c \
          ft_atol.c \
          ft_split.c \
          index.c \
          utils.c \
          utils_2.c \
          utils_3.c \
          parse_utils.c \
          push_logic.c \
          reverse_rotate.c \
          rotate_logic.c \
          swap_logic.c \
          sort_complex.c \
          sort_simple.c \
          sort_medium.c \
          bench.c

OBJS    = $(SRCS:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
