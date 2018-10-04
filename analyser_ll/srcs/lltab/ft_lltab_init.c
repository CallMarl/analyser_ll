/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:28:50 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern t_intarr		g_llfirst;
extern t_intarr		g_llffirst;
extern t_intarr		g_llfollow;
extern int			g_llpiv;
extern int			g_lllast;

static int			ft_lltab_initarr()
{
	int				y;
	int				x;

	x = g_lllast - g_llpiv + 1;
	if (!(ft_utils_initarr(&g_llfirst, x, g_llpiv)))
		return (CODE_ERR1);
	y = ft_utils_getnbrule();
	if (!(ft_utils_initarr(&g_llffirst, x, y)))
		return (CODE_ERR1);
	if (!(ft_utils_initarr(&g_llfollow, x, y)))
		return (CODE_ERR1);
	if (!(ft_utils_alloclltab(&g_lltab, y, x)))
		return (CODE_ERR1);
	return (1);
}

static void			ft_lltab_uninitarr()
{
	ft_utils_uninitarr(&g_llfirst);
	ft_utils_uninitarr(&g_llffirst);
	ft_utils_uninitarr(&g_llfollow);
}

static void		ft_lltab_insert(int *line, int *value, int y)
{
	int			i;

	i = 0;
	while (i < g_lltab.max_x && value[i] != -1)
	{
		line[value[i] - g_llpiv] = y;
		i++;
	}
}

static void			ft_lltab_generate()
{
	int			i;
	t_llderi	*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_lltab_insert(g_lltab.lltab[tmp[i].y - 1], g_llfirst.arr[i], i);
		if(g_llfirst.arr[i][0] == g_lllast)
			ft_lltab_insert(g_lltab.lltab[tmp[i].y - 1], g_llfollow.arr[tmp[i].y - 1], i);
		i++;
	}
}

extern int			ft_lltab_init()
{
	ft_debug_analyser();
	ft_printf("null, $ : %d\n", g_lllast);
	ft_printf("pivot : %d\n", g_llpiv);
	if (ft_lltab_initarr() < 0)
	{
		ft_lltab_uninitarr();
		return (CODE_ERR1);
	}
	ft_lltab_first();
		ft_putendl("\nFirst arr:");
		ft_debug_intarr(&g_llfirst);
		ft_putendl("\nFfirst arr:");
		ft_debug_intarr(&g_llffirst);
	ft_lltab_follow();
		ft_putendl("\nFollow arr:");
		ft_debug_intarr(&g_llfollow);
	ft_lltab_generate();
	ft_debug_lltab(g_lltab);
	return (1);
}
