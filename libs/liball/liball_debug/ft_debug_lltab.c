/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_lltab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:50:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/13 11:26:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern void			ft_debug_lltab(t_lltab lltab)
{
	int				x;
	int				y;

	y = 0;
	if (lltab.lltab != 0)
	{
		ft_printf("x : %d\n", lltab.max_x);
		ft_printf("y : %d\n", lltab.max_y);
		while (y < lltab.max_y - 1)
		{
			x = 0;
			while (x < lltab.max_x)
			{
				ft_printf("%5d", lltab.lltab[y][x]);
				x++;
				if (x < lltab.max_x)
					ft_putstr(", ");
			}
			ft_putchar('\n');
			y++;
		}
		ft_putchar('\n');
	}
}
