# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/02/09 19:31:27 by myakoven         ###   ########.fr        #
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
SRC     	:= split.c dll_utils.c main.c moves.c
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

# makelib:
# 	make -C $(LIBDIR)
# 	cp $(LIBDIR)/$(LIBNAME) .
# 	mv $(LIBNAME) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) -g3 $(CFLAGS) $(LIBFT) dll_utils.c main.c moves.c split.c -I push_swap.h -o $@

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
