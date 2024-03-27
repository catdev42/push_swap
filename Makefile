# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/03/26 02:52:27 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

LIBNAME = libft.a
LIBDIR = ./libft
LIBFT = ./libft/libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= checking.c create.c error_clean.c list_utils.c main.c moves_big.c moves.c sorting.c
OBJS     	= $(SRC:.c=.o)

# BONUS		= 
# BONUS_OBJS	= $(BONUS:.c=.o)

CC      	:= gcc
CFLAGS  	:= -Wall -Wextra -Werror

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# makelib:
# 	make -C $(LIBDIR)
# 	cp $(LIBDIR)/$(LIBNAME) .
# 	mv $(LIBNAME) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) -g3 $(CFLAGS) $(LIBFT) checking.c create.c error_clean.c list_utils.c main.c moves_big.c moves_noprev.c sorting.c -o push_swap

# $(CC) -g $(CFLAGS) ./libft/*.o ./libft/printf/*.o $(OBJS)  -o $@

#	$(CC) -g $(CFLAGS) $^ -o $@
#	$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o push_swap
#	ar -r $(NAME) $(OBJS)

# $(NAME):  $(LIBFUN) $(PRINTF) $(GNL)
# 	ar rc $(NAME) $(LIBFUN) $(PRINTF) $(GNL)

clean:
	rm -f $(OBJS)
	rm -f ./objects/*.o 
	cd $(LIBDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
