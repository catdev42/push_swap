# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/03/28 00:21:40 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

# INCLUDES = ./include

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= checking.c create.c error_clean.c main.c moves_big.c moves.c sorting.c
OBJS     	:= $(SRC:.c=.o)

CC      	:= cc
CFLAGS  	:= -Wall -Wextra -Werror -g

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f ./objects/*.o 
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all
