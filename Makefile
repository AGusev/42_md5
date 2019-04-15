# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 19:26:49 by agusev            #+#    #+#              #
#    Updated: 2019/04/14 23:01:14 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

SRC =	*.c \
		md5/*.c \
		sha224/*.c \
		sha256/*.c \
		sha512/*.c


LIBFT = libft/Makefile

INCLUDE = ssl.h

OBJ = *o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -g -c $(SRC) -I $(INCLUDE)
	@gcc $(FLAGS) -g -o $(NAME) $(OBJ) -L./libft -lft
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[31mObjects files \033[1;31m$(OBJ)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
	@echo "abc" | openssl md5
	@echo "abc" | ./ft_ssl md5
	@echo "\n"
	@echo "abc" | openssl sha224
	@echo "abc" | ./ft_ssl sha224
	@echo "\n"
	@echo "abc" | openssl sha256
	@echo "abc" | ./ft_ssl sha256
	@echo "\n"
	@echo "abc" | openssl sha512
	@echo "abc" | ./ft_ssl sha512
	@echo "\n"
	@rm -f $(NAME) $(OBJ)

