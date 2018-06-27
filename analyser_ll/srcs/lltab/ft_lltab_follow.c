/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/27 17:59:46 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;

static void			ft_lltab_follow_first(int follow, int first)
{
	int				x;

	x = 0;
	while (x < g_lltab.max_x)
	{
		if (g_lltab.lltab[first][x] != -1)
			g_lltab.lltab[follow][x] = g_lltab.lltab[first][x];
		x++;
	}
}

extern int			ft_lltab_follow(t_llderi rule, int y, int ind, int mid)
{
	int				i;
	size_t			j;
	int				tmp;
	t_llderi		*llderi;

	ft_putchar('\n');
	ft_putstr("search ");
	ft_putnbr(rule.y);
	ft_putchar('\n');
	i = 0;
	llderi = (t_llderi *)g_llderi.buff;
	while (i < mid)
	{
		ft_putstr("deri ");
		ft_putendl(ft_itoa(i));
		j = 0;
		while (j < llderi[i].d_size)
		{
			ft_printf("%d ",llderi[i].deri[j]);
			if (llderi[i].deri[j] == rule.y && j < llderi[i].d_size - 1)
			{
				ft_putendl("    find");
				tmp = llderi[i].deri[j + 1];
				if (tmp >= mid)
					g_lltab.lltab[y - 1][tmp - mid + 1] = ind;
				else if (tmp < mid && tmp != rule.y)
					ft_lltab_follow_first(rule.y ,tmp - mid + 1);
			}
			else if (llderi[i].deri[j] == rule.y)
				; // Ajouter $ à suivant
			j++;
		}
	ft_putchar('\n');
		i++;
	}
	return (1);
}
