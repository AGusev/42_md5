# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 19:26:49 by agusev            #+#    #+#              #
#    Updated: 2019/04/03 23:23:16 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

NAME = ft_ssl

FLAGS = -Wall -Wextra -Werror

SOURCES = lib.c main.c print.c extra.c md5.c options.c
# sha224.c sha256.c

INCLUDE = md5.h

OBJS = lib.o main.o print.o extra.o md5.o options.o
# sha256.o sha224.o

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -g -c $(SOURCES) -I $(INCLUDE)
	@gcc	$(FLAGS) -g -o $(NAME) $(OBJS) -L./libft -lft
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[31mObjects files \033[1;31m$(OBJS)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all
