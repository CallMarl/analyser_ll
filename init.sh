#!bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:01:20 by pprikazs          #+#    #+#              #
#    Updated: 2018/05/03 13:59:11 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

new_dir()
{
	if [ ! -d $1 ];
		then
			mkdir $1 &>/dev/null
	fi
}

new_link()
{
	if [ ! -f $2 ];
		then
			ln -sf $1 $2
	fi
}

root=`pwd`

new_link $root/libs/libft/libft.h $root/analyser_ll/includes/libft.h
new_dir $root/analyser_ll/libs
new_link $root/libs/libft/libft.a $root/analyser_ll/libs/libft.a

