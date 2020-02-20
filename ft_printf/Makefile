# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 13:53:08 by ccrivici          #+#    #+#              #
#    Updated: 2020/02/11 20:43:35 by ccrivici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

CC = gcc

NAME = libftprintf.a
SRC = ft_printf.c ft_charc.c ft_numbers.c get_flags.c write_cases.c ft_putstr.c ft_hex_capital.c ft_hex.c ft_numbers_unsigned.c ft_pointer.c
OBJ = $(SRC:.c=.o)
INCLUDE = structures.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so: $(OBJ) $(INCLUDE)
	$(CC) -shared -fPIC -Wl,-soname,libftprintf.so -o libftprintf.so $(OBJ)
