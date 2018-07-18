NAME = liball.a
CC = ar
FLAGS = -Wall -Wextra -Werror

DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
endif

NOFLAGS = no
ifeq ($(NOFLAGS), yes)
	FLAGS = -g -w
endif

INCLUDES = -I./ \

VPATH = ./liball_debug:./liball_import:./liball_utils

#./liball_debug
SRCS = ft_debug_llderi.c \
	   ft_debug_lltab.c \
	   ft_debug_llterm.c
#./liball_import
SRCS += ft_import_llderi.c \
		ft_import_lltab.c \
		ft_import_llterm.c
#./liball_utils
SRCS += ft_utils_alloclltab.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

DEPS = includes/*.h Makefile
DEPS = $(shell find . -regex ".*\.[ch]")

.PHONY: all clean fclean re
.SUFFIXES:

$(OBJ_PATH)%.o : %.c
	gcc $(INCLUDES) -c $< -o $@ $(FLAGS)

$(NAME) : init $(OBJ) $(DEPS)
	@$(CC) -rcs $@ $(OBJ);

all : $(NAME)

init :
	@sh init.sh

clean :
	@$(RM) -f $(OBJ)

fclean : clean
	@$(RM) -f $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all
