# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+          #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2026/05/14 14:32:48 by tireis           #+#    #+#               #
#    Updated: 2026/06/15 14:32:02 by eboualla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c \
        ft_atol.c \
        index.c \
        lst_utils.c \
        lst_utils_2.c \
        parse_utils.c \
        push_logic.c \
        reverse_rotate.c \
        rotate_logic.c \
        swap_logic.c \
        sort_comlex.c \
        sort_simple.c \
        sort_medium.c

OBJS    = $(SRCS:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJS)
	$(CC) $(OBJS) $(PRINTF_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
