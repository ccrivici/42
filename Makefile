# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrivici <ccrivici@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 17:46:20 by ccrivici          #+#    #+#              #
#    Updated: 2019/11/14 11:13:42 by ccrivici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = *.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./
all: $(NAME)
$(NAME):	$(SRCS) libft.h
			gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:			fclean all
