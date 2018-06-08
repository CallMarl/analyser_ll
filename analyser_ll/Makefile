# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 18:58:27 by pprikazs          #+#    #+#              #
#    Updated: 2018/06/08 19:13:38 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = analyser_ll
CC = gcc

DEBUG = no
FLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG), yes)
	FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
endif

NOFLAGS = no
ifeq ($(NOFLAGS), yes)
	FLAGS = -g -w
endif
	
DEPS = includes/*.h Makefile
INCLUDES = -I./includes/

SRCS = ./main.c \
	   ./srcs/ft_analyser_ll.c

OBJ = $(SRCS:./%.c=./%.o)

LIB_DIR = ../libs
LIBS = ./libs/libft.a
export LIB_NEED = ./libft

.PHONY: all clean fclean re
.SUFFIXES:

all : $(NAME)

%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : $(OBJ) $(DEPS)
	@echo "Compilation" $(NAME) "..."
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(OBJ) -o $@ $(LIBS) $(FLAGS)

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all