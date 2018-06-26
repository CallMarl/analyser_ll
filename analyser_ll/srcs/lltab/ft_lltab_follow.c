/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/26 15:27:31 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;

static int			ft_lltab_follow_first(int follow, int first)
{
	int				x;

	x = 0;
	while (x < g_lltab.max_x)
	{
		if (g_lltab.tab[first][x] != -1)
			g_lltab.tab[follow][x] = g_lltab.tab[first][x];
	}
}

extern int			ft_lltab_follow(t_llderi rule, int y, int ind, int mid)
{
	int				i;
	int				j;
	int				tmp;

	i = 0;
	while (i < mid)
	{
		j = 0;
		while (j < g_llderi[i].d_size)
		{
			if (g_llderi[i].deri[j] == rule.y && j < g_llderi[i].d_size - 1)
			{
				tmp = g_llderi[i].deri[j];
				if (tmp >= mid)
					g_lltab.lltab[y - 1][rule.deri[i] - mid] = ind;
				else if (tmp < mid && tmp != rule.y)
					ft_lltab_follow_first(rule.y ,tmp);
			}
			else if (g_llderi[i].deri[j] == rule.y)
				; // Ajouter $ à suivant
			j++;
		}
		i++;
	}
}
