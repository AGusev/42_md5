# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 16:34:50 by agusev          #+#    #+#              #
#    Updated: 2019/04/04 15:33:17 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ./src/ft_*.c ./ft_printf/*.c

INCLUDE = header

OBJS = ./src/ft_*.o ./ft_printf/*.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SOURCES) -I $(INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
