# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 23:30:31 by agusev            #+#    #+#              #
#    Updated: 2019/04/19 04:11:12 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC = 	./*.c

MLIB = make -C libftprintf

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
#	$(MLIB)
	gcc -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MLIB) clean

fclean: clean
	rm -f $(NAME)
#	$(MLIB) fclean

re: fclean all

r: fclean all
	@echo
	@openssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@./ft_ssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@openssl sha224 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@./ft_ssl sha224 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@openssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@./ft_ssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@openssl sha384 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@./ft_ssl sha384 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@openssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@./ft_ssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo
	@echo
	@echo "abc" | openssl md5
	@echo "abc" | ./ft_ssl md5
	@echo "abc" | openssl sha224
	@echo "abc" | ./ft_ssl sha224
	@echo "abc" | openssl sha256
	@echo "abc" | ./ft_ssl sha256
	@echo "abc" | openssl sha384
	@echo "abc" | ./ft_ssl sha384
	@echo "abc" | openssl sha512
	@echo "abc" | ./ft_ssl sha512
	@echo "\n"
	@echo "\n"
	@rm -f $(NAME)
