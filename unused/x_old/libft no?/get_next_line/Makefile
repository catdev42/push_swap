# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/25 18:58:02 by myakoven          #+#    #+#              #
#    Updated: 2024/02/07 22:45:47 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= get_next_line.a

# LIBNAME = libft.a
# LIBDIR = ./libft

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= ../includes
SRC     	:= get_next_line.c 
# get_next_line_utils.c
OBJS     	= $(SRC:.c=.o)

# BONUS		= 
# BONUS_OBJS	= $(BONUS:.c=.o)

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 

clean:
	rm -f *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
