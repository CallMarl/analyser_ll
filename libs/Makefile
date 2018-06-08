# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 18:58:05 by pprikazs          #+#    #+#              #
#    Updated: 2018/06/08 19:12:51 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = $(shell pwd)/

ifeq ($(LIB_NEED),)
	LIB_NEED = './libft'
endif

.PHONY: all clean fclean re

all :
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) -C $(ROOT)$$dir; \
		done

clean : 
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) $@ -C $(ROOT)$$dir; \
		done

fclean :
	@for dir in $(LIB_NEED) ; \
		do \
			$(MAKE) $@ -C $(ROOT)$$dir; \
		done

re :
	$(MAKE) fclean
	$(MAKE) all
