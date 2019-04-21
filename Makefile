# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 23:30:31 by agusev            #+#    #+#              #
#    Updated: 2019/04/20 18:49:17 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC =	./functions/*.c \
		./md5_sha/*.c \
		./extra/*.c \
		./read_print/*.c

LIB = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	gcc -w -Wall -Wextra -Werror $(SRC) $(LIB) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean all

	@echo "\n<-------------------------------------------------->\n"
	@echo "Can they MD5 a file?\n"
	@echo 'is md5("salt") a salted hash? :thonking_face:' > /tmp/file
	@./ft_ssl md5 /tmp/file
	@md5 /tmp/file
	@openssl md5 /tmp/file

	@echo "\n<-------------------------------------------------->\n"
	@echo "Can they do it quietly?\n"

	@echo "\n<-------------------------------------------------->\n"
	@echo "REVERSE REVERSE!\n"
	@md5 -r /tmp/file
	@./ft_ssl md5 -r /tmp/file

	@echo "\n<-------------------------------------------------->\n"
	@echo "Print it back now, Y'all!\n"
	@echo "Magic mirror on the wall, think I wanna smash them all?" | md5 -p
	@echo "Speed up now, Gas Pedal??" | ./ft_ssl md5 -p

	@echo "\n<-------------------------------------------------->\n"
	@echo "SHA (Some Hipster Algorithm)\n"
	@echo "Lorem ipsum dolor amet thundercats letterpress cray portland\
	cornhole coloring book twee prism hexagon mixtape pork belly hell of\
	four dollar toast disrupt. Hammock PBR&B bicycle rights selvage street\
	art, lumbersexual gochujang vegan hot chicken. Meggings drinking\
	vinegar biodiesel poke roof party tote bag cloud bread ethical.\
	Glossier flannel 8-bit hexagon selvage adaptogen farm-to-table offal\
	knausgaard pickled." > some_hipster_ipsum
	@shasum -a 256 some_hipster_ipsum > some_hipster_ipsum_sum
	@./ft_ssl sha256 some_hipster_ipsum > flip_some_hipsum


	@echo "\n"
	@openssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"
	@./ft_ssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"
	@openssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"
	@./ft_ssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"
	@openssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"
	@./ft_ssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo "\n"

	@echo "\n"
	@echo "abc" | openssl md5
	@echo "\n"
	@echo "abc" | ./ft_ssl md5
	@echo "\n"
	@echo "abc" | openssl sha224
	@echo "\n"
	@echo "abc" | ./ft_ssl sha224
	@echo "\n"
	@echo "abc" | openssl sha256
	@echo "\n"
	@echo "abc" | ./ft_ssl sha256
	@echo "\n"
	@echo "abc" | openssl sha384
	@echo "\n"
	@echo "abc" | ./ft_ssl sha384
	@echo "\n"
	@echo "abc" | openssl sha512
	@echo "\n"
	@echo "abc" | ./ft_ssl sha512
	@echo "\n"



	@echo "\n"



	@rm -f $(NAME)
