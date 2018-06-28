/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/28 14:14:09 by pprikazs         ###   ########.fr       */
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

	i = 0;
	llderi = (t_llderi *)g_llderi.buff;
	while (i < mid)
	{
		j = 0;
		while (j < llderi[i].d_size)
		{
			if (llderi[i].deri[j] == rule.y && j < llderi[i].d_size - 1)
			{
				tmp = llderi[i].deri[j + 1];
				if (tmp >= mid)
					g_lltab.lltab[y - 1][tmp - mid] = ind;
				else if (tmp < mid && tmp != rule.y)
					ft_lltab_follow_first(rule.y ,tmp);
				tmp = llderi[i].deri[j + 1];
			}
			else if (llderi[i].deri[j] == rule.y)
				; // Ajouter $ à suivant
			j++;
		}
		i++;
	}
	return (1);
}
