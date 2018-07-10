# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 18:58:42 by pprikazs          #+#    #+#              #
#    Updated: 2018/07/10 15:54:54 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT = $(shell pwd)/

PRGS = $(ROOT)/analyser_ll/ \
	   $(ROOT)/test_import/

.PHONY: all clean fclean re

all :
	@sh init.sh
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) -C $$dir; \
		done

clean : 
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) $@ -C $$dir; \
		done

fclean :
	@for dir in $(PRGS) ; \
		do \
			$(MAKE) $@ -C $$dir; \
		done

re :
	$(MAKE) fclean
	$(MAKE) all
