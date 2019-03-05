# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: balvyn-s <balvyn-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 20:03:27 by balvyn-s          #+#    #+#              #
#    Updated: 2018/12/15 15:42:55 by balvyn-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wextra -Wall -Werror -I./includes/
GCC = gcc $(FLAG)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

$(NAME):
	$(GCC) -c *.c
	ar rc $(NAME) *.o
