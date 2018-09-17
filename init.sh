#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:01:20 by pprikazs          #+#    #+#              #
#    Updated: 2018/07/10 15:53:31 by pprikazs         ###   ########.fr        #
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

new_dir $root/analyser_ll/libs
new_dir $root/analyser_ll/obj
new_link $root/libs/libft/libft.h $root/analyser_ll/includes/libft.h
new_link $root/libs/liball/liball.h $root/analyser_ll/includes/liball.h
new_link $root/libs/libft/libft.a $root/analyser_ll/libs/libft.a
new_link $root/libs/liball/liball.a $root/analyser_ll/libs/liball.a

new_link $root/libs/libft/libft.h $root/test_import/includes/libft.h
new_link $root/libs/liball/liball.h $root/test_import/includes/liball.h
new_dir $root/test_import/libs
new_dir $root/test_import/obj
new_link $root/libs/libft/libft.a $root/test_import/libs/libft.a
new_link $root/libs/liball/liball.a $root/test_import/libs/liball.a
