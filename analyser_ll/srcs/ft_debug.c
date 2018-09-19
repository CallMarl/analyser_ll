/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/19 18:44:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "analyser_ll.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern t_buff		g_llterm;

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

extern void			ft_debug_analyser()
{
	ft_debug_llterm(g_llterm);
	ft_debug_llderi(g_llderi);
	ft_debug_lltab(g_lltab);
}

extern void			ft_debug_intarr(int **arr, int x, int y)
{
	int				i;
	int				j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%3d", arr[i][j]);
			if (j + 1 != x)
				ft_putstr(", ");
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
