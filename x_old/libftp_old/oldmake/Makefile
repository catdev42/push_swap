# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/01/31 17:13:31 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

LIBFTPRINTFDIR = ./libftprintf

LIBNAME = libft.a
LIBDIR = ./libft

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= ft_printf_utils.c ft_printf.c ft_printhex.c ft_printptr.c ft_printuns.c
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

makelib:
	make -C $(LIBDIR)
	cp $(LIBDIR)/$(LIBNAME) $(LIBFTPRINTFDIR)
	mv $(LIBFTPRINTFDIR)/$(LIBNAME) $(LIBFTPRINTFDIR)/$(NAME)

$(NAME): makelib $(OBJS)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
