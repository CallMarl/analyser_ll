/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/20 16:33:30 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
extern t_lltab		g_lltab;
extern int			g_llpiv;
extern int			g_lllast;

/*
** Calcule de du nombre de regle, car g_llderi.cr correspond au nombre
** de dérivation et non au nombre de règle (cas du ou).
*/

extern t_intarr		*ft_alloc_intarr(int x, int y)
{
	t_intarr		*arr;
	int				i;
	int				j;

	arr = 0;
	if (!(arr = (t_intarr *)ft_memalloc(sizeof(t_intarr))))
		return (0);
	arr->max_x = x;
	arr->max_y = y;
	if (!(arr->arr = (int **)ft_memalloc(sizeof(int *) * y)))
		return (0);
	i = 0;
	while (i < y)
	{
		if (!(arr->arr[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (0);
		j = 0;
		while (j < x + 1)
		{
			arr->arr[i][j] = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

extern int			ft_lltab_getnbrule(void)
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
	return (nb);
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

static void		ft_lltab_initaux(t_intarr *first, t_intarr *follow)
{
	int			i;
	t_llderi	*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_lltab_insert(g_lltab.lltab[tmp[i].y - 1], first->arr[i], i);
		if(first->arr[i][0] == g_lllast)
			ft_lltab_insert(g_lltab.lltab[tmp[i].y - 1], follow->arr[tmp[i].y - 1], i);
		i++;
	}
}

extern int			ft_lltab_init()
{
	int				ret;
	int				y;
	t_intarr		*first;
	t_intarr		*follow;

	ft_debug_analyser();
	ft_putstr("null && $ value : ");
	ft_putnbr(g_lllast);
	ft_putchar('\n');
	ft_putstr("pivot :");
	ft_putnbr(g_llpiv);
	ft_putchar('\n');
	y = ft_lltab_getnbrule();
	first = 0;
	follow = 0;
	ret = 1;
	if (!(first = ft_alloc_intarr(g_llterm.cr + 1, g_llpiv)))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0 && !(follow = ft_alloc_intarr(g_llterm.cr + 1, y)))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0)
	{
		ft_lltab_initfirst(first);
				ft_putendl("\nFirst arr:");
				ft_debug_intarr(first);
		ft_lltab_initfollow(follow, first);
			{
				ft_putendl("\nFirst arr:");
				ft_debug_intarr(first);
				ft_putendl("\nFollow arr:");
				ft_debug_intarr(follow);
			}
		ret = ft_utils_alloclltab(&g_lltab, y, g_llterm.cr + 1);
		ft_putendl("end");
		if (ret > 0)
			ft_lltab_initaux(first, follow);
	}
	ft_debug_lltab(g_lltab);
	return (ret);
}
