/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_lltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:24:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 18:26:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern void			ft_del_lltab(t_lltab *lltab)
{
	int				y;
	int				x;

	if (lltab->lltab != 0)
	{
		y = 0;
		while (y < lltab->max_y)
		{
			if (lltab->lltab[y] != 0)
			{
				x = 0;
				while (x < lltab->max_x)
					lltab->lltab[y][x++] = 0;
			}
			y++;
		}
		y = 0;
		while (y < lltab->max_y)
			ft_memdel((void **)&lltab->lltab[y++]);
		ft_memdel((void **)lltab->lltab);
		lltab->max_x = 0;
		lltab->max_y = 0;
	}
}
