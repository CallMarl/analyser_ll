NAME = liball.a
CC = ar
FLAGS = -Wall -Wextra -Werror

ROOT = $(shell dirname `pwd`)
DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -g -w
endif

INCLUDES = -I./ \

SRCS = ./liball_debug/ft_debug_llderi.c \
	   ./liball_debug/ft_debug_lltab.c \
	   ./liball_debug/ft_debug_llterm.c \

OBJ = $(SRCS:%.c=%.o)
DEPS = includes/*.h Makefile
DEPS = $(shell find . -regex ".*\.[ch]") 

.PHONY: all clean fclean re
.SUFFIXES:

%.o : %.c
	gcc $(INCLUDES) -c $< -o $@ $(FLAGS)
	
$(NAME) : $(OBJ) $(DEPS)
	@$(CC) -rc $@ $(OBJ);

all : $(NAME)

clean :
	@$(RM) -f $(OBJ)

fclean : clean
	@$(RM) -f $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all
