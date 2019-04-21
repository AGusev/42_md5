# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 11:27:05 by agusev            #+#    #+#              #
#    Updated: 2019/04/21 03:04:55 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ssl
SRC	=		./*c \
			./md5/*c \
			./sha224/*c \
			./sha256/*c \
			./sha384/*c \
			./sha512/*c

LIB = libft/libft.a
PRF = libft/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
	gcc -w -Wall -Wextra -Werror $(SRC) $(LIB) $(PRF) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean all

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "		Can they MD5 a file?"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo 'is md5("salt") a salted hash? :thonking_face:' > /tmp/file
	@./ft_ssl md5 /tmp/file
	@md5 /tmp/file
	@openssl md5 /tmp/file

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "Can they do it quietly?"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "diff <(md5 /tmp/file) <(./ft_ssl md5 /tmp/file)"


	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "REVERSE REVERSE!"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@md5 -r /tmp/file
	@./ft_ssl md5 -r /tmp/file

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "Print it back now, Y'all!"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "Magic mirror on the wall, think I wanna smash them all?" | md5 -p
	@echo "Speed up now, Gas Pedal??" | ./ft_ssl md5 -p


	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "SHA (Some Hipster Algorithm)"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "Lorem ipsum dolor amet thundercats letterpress cray portland\
	cornhole coloring book twee prism hexagon mixtape pork belly hell of\
	four dollar toast disrupt. Hammock PBR&B bicycle rights selvage street\
	art, lumbersexual gochujang vegan hot chicken. Meggings drinking\
	vinegar biodiesel poke roof party tote bag cloud bread ethical.\
	Glossier flannel 8-bit hexagon selvage adaptogen farm-to-table offal \
	knausgaard pickled." > some_hipster_ipsum
	@shasum -a 256 some_hipster_ipsum > some_hipster_ipsum_sum
	@./ft_ssl sha256 some_hipster_ipsum > flip_some_hipsum
	@echo "diff some_hipster_ipsum_sum flip_some_hipsum"


	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "NO FLAGS"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo -n "abc" > test

	@echo "\nopenssl MD5 : "
	@openssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | openssl md5
	@echo "\nft_ssl MD5 : "
	@./ft_ssl md5 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | ./ft_ssl md5

	@echo "\nopenssl SHA224 : "
	@openssl sha224 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | openssl sha224
	@echo "\nft_ssl SHA224: "
	@./ft_ssl sha224 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | ./ft_ssl sha224

	@echo "\nopenssl SHA256 : "
	@openssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | openssl sha256
	@echo "\nft_ssl SHA256 : "
	@./ft_ssl sha256 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | ./ft_ssl sha256

	@echo "\nopenssl SHA384 : "
	@openssl sha384 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | openssl sha384
	@echo "\nft_ssl SHA384 : "
	@./ft_ssl sha384 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | ./ft_ssl sha384

	@echo "\nopenssl SHA512 : "
	@openssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | openssl sha512
	@echo "\nft_ssl SHA512 : "
	@./ft_ssl sha512 /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test
	@echo -n "abc" | ./ft_ssl sha512

	@echo "\n"

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "FLAG -s"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "\nft_ssl MD5 : "
	@./ft_ssl md5 -s /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test

	@echo "\nft_ssl SHA224: "
	@./ft_ssl sha224 -s /nfs/2019/a/agusev/Desktop/projects/ft_ssl/tests

	@echo "\nft_ssl SHA256 : "
	@./ft_ssl sha256 -s /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test

	@echo "\nft_ssl SHA384 : "
	@./ft_ssl sha384 -s /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test

	@echo "\nft_ssl SHA512 : "
	@./ft_ssl sha512 -s /nfs/2019/a/agusev/Desktop/projects/ft_ssl/test

	@echo "\n"

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "FLAG -p"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "\nft_ssl MD5 : "
	@echo "abc" | ./ft_ssl md5 -p

	@echo "\nft_ssl SHA224: "
	@echo "abc" | ./ft_ssl sha224 -p

	@echo "\nft_ssl SHA256 : "
	@echo "abc" | ./ft_ssl sha256 -p

	@echo "\nft_ssl SHA384 : "
	@echo "abc" | ./ft_ssl sha384 -p

	@echo "\nft_ssl SHA512 : "
	@echo "abc" | ./ft_ssl sha512 -p

	@echo "\n"


	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "FLAG -r"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "\nft_ssl MD5 : "
	@./ft_ssl md5 -r test

	@echo "\nft_ssl SHA224: "
	@./ft_ssl sha224 -r test

	@echo "\nft_ssl SHA256 : "
	@./ft_ssl sha256 -r test

	@echo "\nft_ssl SHA384 : "
	@./ft_ssl sha384 -r test

	@echo "\nft_ssl SHA512 : "
	@./ft_ssl sha512 -r test


	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "FLAG -q"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "\nft_ssl MD5 : "
	@./ft_ssl md5 -q test

	@echo "\nft_ssl SHA224: "
	@./ft_ssl sha224 -q test

	@echo "\nft_ssl SHA256 : "
	@./ft_ssl sha256 -q test

	@echo "\nft_ssl SHA384 : "
	@./ft_ssl sha384 -q test

	@echo "\nft_ssl SHA512 : "
	@./ft_ssl sha512 -q test

		@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "other cases"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"

	@echo "\nft_ssl MD5 : (-stest)"
	@./ft_ssl md5 -stest

	@echo "\nft_ssl SHA224: (-sr)"
	@./ft_ssl sha224 -sr test

	@echo "\nft_ssl SHA256 : (2 param)"
	@./ft_ssl sha256  test some_hipster_ipsum

	@echo "\nft_ssl SHA384 : (-r -s)"
	@./ft_ssl sha384 -r -s test some_hipster_ipsum

	@echo "\nft_ssl SHA512 : (-stest some_hipster_ipsum)"
	@./ft_ssl sha512 -stest some_hipster_ipsum

	@echo "\n"

	@echo "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
	@echo "THE END"
	@echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n"
	@echo "\n"
	@rm -f $(NAME)
