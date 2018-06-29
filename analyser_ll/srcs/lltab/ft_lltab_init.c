/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 15:58:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

/*
** Calcule de du nombre de regle, car g_llderi.cr correspond au nombre 
** de dérivation et non au nombre de règle (cas du ou).
*/

static int			ft_lltab_getnbrule(void)
{
	size_t			i;
	int				nb;
	t_llderi		tmp;

	i = 0;
	nb = -1;
	while (i < g_llderi.cr)
	{
		tmp = ((t_llderi *)g_llderi.buff)[i];
		nb = (nb < tmp.y) ? tmp.y : nb;
		i++;
	}
	return (nb + 1);
}

static void			ft_lltab_initaux(void)
{
	int				i;

	i = 0;
	while (i < g_llpiv)
	{
		ft_lltab_first(((t_llderi *)g_llderi.buff)[i], \
				((t_llderi *)g_llderi.buff)[i].y , i);
		i++;
		}
	i = 0;
	while (i < g_llpiv)
	{
		if (ft_lltab_eps(((t_llderi *)g_llderi.buff)[i]) == 1)
		{
			ft_lltab_follow(((t_llderi *)g_llderi.buff)[i], \
					((t_llderi *)g_llderi.buff)[i].y, i);
		}
		i++;
	}
}

static int			ft_lltab_alloc(int y, int x)
{
	int				i;
	int				j;

	if (!(g_lltab.lltab = (int **)ft_memalloc(sizeof(int *) * y)))
		return (CODE_ERR1);
	i = 0;
	while (i < y)
	{
		if (!(g_lltab.lltab[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (CODE_ERR1);
		j = 0;
		while (j < x + 1)
		{
			g_lltab.lltab[i][j] = -1;
			j++;
		}
		i++;
	}
	g_lltab.max_y = y;
	g_lltab.max_x = x + 1;
	return (1);
}

extern int			ft_lltab_init(t_buff rule, t_buff term)
{
	int				ret;
	int				max_y;

	ret = ft_llderi_init(&rule, &term);
	if (ret > 0)
	{
		max_y = ft_lltab_getnbrule();
		ret = ft_lltab_alloc(max_y, term.cr);
	}
	g_llpiv = rule.cr;
	if (ret > 0)
		ft_lltab_initaux();
	ft_debug_term(term);
	ft_debug_deri();
	ft_debug_lltab();
	return (ret);
}
