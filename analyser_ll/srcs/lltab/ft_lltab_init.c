/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/18 22:43:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
extern t_lltab		g_lltab;
extern int			g_llpiv;

/*
** Calcule de du nombre de regle, car g_llderi.cr correspond au nombre
** de dérivation et non au nombre de règle (cas du ou).
*/

static int			**ft_alloc_intarr(int x, int y)
{
	int				**arr;
	int				i;
	int				j;

	arr = 0;
	if (!(arr = (int **)ft_memalloc(sizeof(int *) * y)))
		return (0);
	i = 0;
	while (i < y)
	{
		if (!(arr[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (0);
		j = 0;
		while (j < x + 1)
		{
			arr[i][j] = -1;
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
	return (nb + 1);
}

static void		ft_lltab_insert(int *line, int *value, int y)
{
	int			i;

	while (i < g_lltab.max_x && value[i] != -1)
	{
		line[value[i] - g_llpiv] = y;
		i++;
	}
}

static void		ft_lltab_initaux(int **first, int **follow)
{
	int			i;
	t_llderi	*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_lltab_insert(g_lltab.lltab[tmp[i].y], first[i], tmp[i].y);
		if(first[i][0] == - 1)
			ft_lltab_insert(g_lltab.lltab[tmp[i].y], follow[tmp[i].y], tmp[i].y);
	}
}

extern int			ft_lltab_init()
{
	int				ret;
	int				y;
	int				**first;
	int				**follow;

	y = ft_lltab_getnbrule();
	first = 0;
	follow = 0;
	if ((first = ft_alloc_intarr(g_llterm.cr + 1, g_llpiv)))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0 && !(follow = ft_alloc_intarr(g_llterm.cr + 1, y)))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0)
	{
		ft_lltab_initfirst(first);
		ft_lltab_initfollow(follow, first);
		ret = ft_utils_alloclltab(&g_lltab, y, g_llterm.cr + 1);
		if (ret > 0)
			ft_lltab_initaux(first, follow);
	}
	ft_debug_analyser();
	return (ret);
}
