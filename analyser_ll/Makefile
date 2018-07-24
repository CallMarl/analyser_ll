# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 18:58:27 by pprikazs          #+#    #+#              #
#*   Updated: 2018/07/24 16:15:19 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = analyser_ll
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

VPATH = .:./srcs:./srcs/export:./srcs/lltab:./srcs/parse

#./
SRCS = main.c
#./srcs/
SRCS += ft_analyser_ll.c \
	   ft_debug.c \
	   ft_error.c \
	   ft_global.c
#./srcs/export/
SRCS += ft_export_value.c \
		ft_export_llderi.c \
		ft_export_lltab.c \
		ft_export_llterm.c
#./srcs/lltab/
SRCS += ft_llderi_init.c \
	   ft_lltab_eps.c \
	   ft_lltab_first.c \
	   ft_lltab_follow.c \
	   ft_lltab_init.c
#./srcs/parse
SRCS += ft_parse_gramma.c \
	   ft_parse_readline.c \
	   ft_parse_readrules.c \
	   ft_parse_readterm.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

HOME = no
LIB_DIR = ../libs
ifeq ($(HOME),yes)
	LIBS = -Wl,--start-group \
	       ./libs/libft.a \
	       ./libs/liball.a \
	       -Wl,--end-group
else
	LIBS = ./libs/libft.a \
		   ./libs/liball.a
endif

export LIB_NEED = ./libft \
	./liball

.PHONY: all clean fclean re
.SUFFIXES:

$(OBJ_PATH)%.o : %.c
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : $(OBJ) $(DEPS)
	@$(MAKE) -C $(LIB_DIR)
	@$(CC) $(OBJ) -o $@ $(LIBS) $(FLAGS)

all : $(NAME)

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)

fclean :
	@$(MAKE) fclean -C $(LIB_DIR)
	@rm -f $(OBJ) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

lclean :
	@rm -f $(OBJ)

lfclean :
	@rm -f $(OBJ) $(NAME)

lre :
	@$(MAKE) flclean
	@$(MAKE) all
