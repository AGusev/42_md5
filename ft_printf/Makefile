# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/13 19:33:35 by agusev            #+#    #+#              #
#    Updated: 2019/03/29 16:36:59 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	ft_printf.c \
		srcs/conversions/conversion_d_i.c \
		srcs/conversions/conversion_u_cap_d_cap_u.c \
		srcs/conversions/conversion_o_cap_o.c \
		srcs/conversions/conversion_x_cap_x.c \
		srcs/conversions/conversion_c.c \
		srcs/conversions/conversion_s.c \
		srcs/conversions/conversion_wide_s.c \
		srcs/conversions/conversion_f.c \
		srcs/conversions/conversions.c \
		srcs/conversions/conversion_b.c \
		srcs/conversions/conversion_p.c \
		srcs/conversions/conversion_wide_c.c \
		srcs/formats/adding_minus.c \
		srcs/formats/adding_precision_string.c \
		srcs/formats/adding_width_null_char.c \
		srcs/formats/handle_width.c \
		srcs/formats/adding_plus.c \
		srcs/formats/adding_space.c \
		srcs/formats/handle_format.c \
		srcs/formats/parse_flags.c \
		srcs/formats/adding_precision_number.c \
		srcs/formats/adding_width.c \
		srcs/formats/handle_flags.c \
		srcs/formats/handle_precision.c


OFILES =./ft_printf.o \
		./conversion_d_i.o \
		./conversion_u_cap_d_cap_u.o \
		./conversion_o_cap_o.o \
		./conversion_x_cap_x.o \
		./conversion_b.o \
		./conversion_p.o \
		./conversion_wide_c.o \
		./conversions.o \
		./conversion_c.o \
		./conversion_s.o \
		./conversion_wide_s.o \
		./conversion_f.o\
		./adding_minus.o \
		./adding_precision_string.o \
		./adding_width_null_char.o \
		./handle_width.o \
		./adding_plus.o \
		./adding_space.o \
		./handle_format.o \
		./parse_flags.o \
		./adding_precision_number.o \
		./adding_width.o \
		./handle_flags.o \
		./handle_precision.o

INCLUDES = -I ft_printf.h
LIBFT_H = libft/libft.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;36m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME):
	@echo "$(GREEN)GENERATING libft.a$(RESET)"
	make -C libft
	gcc $(FLAGS) $(INCLUDES) -c $(SRCS)
	@echo "$(GREEN)GENERATING OFILES$(RESET)"
	ar rc $(NAME) $(OFILES) ./libft/*.o
	ranlib $(NAME)
	@echo "$(GREEN)COMPILING libftprintf.a$(RESET)"
	@echo "$(BLUE)COMPLETED$(RESET)"

mclean :
	/bin/rm -f a.out
	@echo "$(RED)DELETING a.out$(RESET)"

clean:
	make -C libft clean
	/bin/rm -f $(OFILES)
	@echo "$(RED)DELETING objects libftprintf.a$(RESET)"
	@echo "$(BLUE)COMPLETED$(RESET)"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "$(RED)DELETING libftprintf.a$(RESET)"
	make -C libft fclean
	@echo "$(BLUE)COMPLETED$(RESET)"

re: fclean all
