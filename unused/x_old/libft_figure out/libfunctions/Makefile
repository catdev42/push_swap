# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 15:27:14 by myakoven          #+#    #+#              #
#    Updated: 2024/02/04 19:41:19 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libfunctions.a

# GNLNAME = get_next_line.a
# GNLDIR = ./get_next_line
# GNL = ./get_next_line/get_next_line.a

# PRINTFNAME = printf.a
# PRINTFDIR = ./printf
# PRINTF = ./printf/printf.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

HEADERS 	:= .
SRC     	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c  ft_lstnew.c ft_lstsize.c ft_lstmap.c 

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

# makegnl:
# 	make -C $(GNLDIR)
# # cp $(GNL) .
# # mv $(GNLNAME) $(NAME)

# makeprintf:
# 	make -C $(PRINTFDIR)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f *.o 
	rm -f printf/*.o
# cd $(GNLDIR) && make clean
# cd $(PRINTFDIR) && make clean


fclean: clean
	rm -rf $(NAME)
#	cd $(GNLDIR) && make fclean
#	cd $(PRINTFDIR) && make fclean

	
re: fclean all

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)


#cc $(CFLAGS) -c $(SRC) -I $(HEADERS)
