# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 14:29:16 by raviz-es          #+#    #+#              #
#    Updated: 2024/01/14 19:41:11 by raviz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_print_hex.c ft_print_num.c ft_print_str.c ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = cc

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -c $(SRCS)
		ar -rc $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re