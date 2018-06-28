/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/28 15:46:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "analyser_ll.h"

extern t_lltab		g_lltab;
extern t_buff		g_llderi;

extern void			ft_debug_lltab(void)
{
	int				x;
	int				y;

	y = 0;
	if (g_lltab.lltab != 0)
	{
		ft_printf("x : %d\n", g_lltab.max_x);
		ft_printf("y : %d\n", g_lltab.max_y);
		while (y < g_lltab.max_y - 1)
		{
			x = 0;
			while (x < g_lltab.max_x)
			{
				ft_printf("%5d", g_lltab.lltab[y][x]);
				x++;
				if (x < g_lltab.max_x)
					ft_putstr(", ");
			}
			ft_putchar('\n');
			y++;
		}
		ft_putchar('\n');
	}
}

extern void			ft_debug_deri(void)
{
	size_t			i;
	size_t			j;
	t_llderi		*tmp;

	tmp = (t_llderi *)g_llderi.buff;
	i = 0;
	while (i < g_llderi.cr)
	{
		ft_putstr("\nderi rule : ");
		ft_putstr(tmp[i].rule);
		ft_putstr("\nderi index : ");
		ft_putnbr(tmp[i].y);
		ft_putstr("\nnb vals : ");
		ft_putnbr(tmp[i].d_size);
		ft_putstr("\nderi vals : ");
		j = 0;
		while (j < tmp[i].d_size)
		{
			(j == 0) ? ft_putstr("{") : ft_putstr(", ");
			ft_putnbr((int)(tmp[i].deri[j]));
			j++;
			if (j == tmp[i].d_size)
				ft_putendl("}\n");
		}
		i++;
	}
	ft_putchar('\n');
}

extern void			ft_debug_rule(t_buff rule)
{
	t_rule			tmp;
	size_t			i;

	i = 0;
	while (i < rule.cr)
	{
		tmp = ((t_rule *)rule.buff)[i];
		ft_putstr("rule index : ");
		ft_putnbr(tmp.i);
		ft_putchar('\n');
		ft_putstr("rule : ");
		ft_putendl(tmp.rule);
		ft_putstr("derivation : ");
		ft_putendl(tmp.deri);
		i++;
	}
	ft_putchar('\n');
}

/*
** Bien que non présent dans le display de ce debugging le caractere `ε`
** est implicitement inclut dans le table d'analyse ll.
*/

extern void			ft_debug_term(t_buff term)
{
	t_term			tmp;
	size_t			i;

	i = 0;
	while (i < term.cr)
	{
		tmp = ((t_term *)term.buff)[i];
		ft_putstr("term : ");
		ft_putendl(tmp.term);
		i++;
	}
	ft_putchar('\n');
}
