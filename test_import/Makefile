# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 18:58:27 by pprikazs          #+#    #+#              #
#*   Updated: 2018/07/17 15:18:01 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = test_import
CC = gcc
FLAGS = -Wall -Wextra -Werror

DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
endif

NOFLAGS = no
ifeq ($(NOFLAGS), yes)
	FLAGS = -g -w
endif

DEPS = includes/*.h Makefile
INCLUDES = -I./includes/

VPATH = .:./srcs

#./
SRCS = main.c
#./srcs/
SRCS += ft_test_import.c \
	   ft_debug.c \
	   ft_error.c \
	   ft_global.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIB_DIR = ../libs
LIBS = -Wl,--start-group \
	   ./libs/libft.a \
	   ./libs/liball.a \
	   -Wl,--end-group

export LIB_NEED = ./libft \
	./liball

.PHONY: all clean fclean re
.SUFFIXES:

$(OBJ_PATH)%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : init $(OBJ) $(DEPS)
	@echo "Compilation" $(NAME) "..."
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(OBJ) -o $@ $(LIBS) $(FLAGS)

all : $(NAME)

init :
	@sh init.sh

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all
