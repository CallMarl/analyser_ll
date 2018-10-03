/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/21 03:33:45 by                  ###   ########.fr       */
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

extern void			ft_utils_uninitarr(t_intarr *arr)
{
	int				i;
	if (arr->arr != 0)
	{
		while (arr->arr[i] != 0 && i < arr->max_y)
			ft_memdel((void **)&(arr->arr[i++]));
		ft_memdel((void **)&(arr->arr));
	}
	arr->max_x = 0;
	arr->max_y = 0;
}

extern int			ft_utils_initarr(t_intarr *arr, int x, int y)
{
	int				i;
	int				j;

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
	return (1);
}

extern int			ft_utils_getnbrule(void)
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
	if (!(ft_utils_initarr(&g_llffirst, x, y)))
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
	ft_printf("null && $ value : %d", g_lllast);
	ft_printf("pivot : %d", g_llpiv);
	if (ft_lltab_initarr() < 0)
	{
		ft_lltab_uninitarr();
		return (CODE_ERR1);
	}
	ft_putendl("ici");
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

/*
** Calcule de du nombre de regle, car g_llderi.cr correspond au nombre
** de dérivation et non au nombre de règle (cas du ou).
*/


/*
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

extern int			ft_lltab_init()
{
	int				ret;
	int				y;
	t_intarr		*first;
	t_intarr		*follow;

	ft_debug_analyser();
	ft_printf("null && $ value : %d", g_lllast);
	ft_printf("pivot : %d", g_llpiv);
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
*/
