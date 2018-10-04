/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:45:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:30:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pour toute production premier de S:
**
** Si la règle dérivé corresponds à une règle de la forme S :: ε alors premier(S)
** équivaux à ε
**
** Si la règle dérivé correspond à une règle de la forme S :: a alors premier(S)
** équivaux à a
**
** Si la règle dérivé correspond à une règle de la forme S :: AB si il existe une
** règle A tel que A :: ε alors premier(S) équivaux à l'ensembles des premier(A)
** exclu ε et l'ensemble des premier(B). A lors du calcule de Premie(A) on inclura
** ε à premier de A.
**
** Sinon si il existe une règle S :: AB telques Premier(A) n'est jamais équivalent
** à ε alors Premier(S) équivaux premier(A)
*/

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_intarr		g_llfirst;
extern t_intarr		g_llffirst;
extern int			g_llpiv;
extern int			g_lllast;

static int			ft_lltab_insertterm(int val, int y, int ind)
{
		if (val == g_lllast)
		{
			ft_utils_insertnull(g_llfirst.arr[ind]);
			ft_utils_insertnull(g_llffirst.arr[y - 1]);
			return (1);
		}
		if (val >= g_llpiv)
		{
			ft_utils_insert(g_llfirst.arr[ind], &val, 1);
			ft_utils_insert(g_llffirst.arr[y - 1], &val, 1);
			return (1);
		}
		return (0);
}


static int			ft_lltab_initfirst(t_llderi rule, int y, int ind)
{
	size_t			i;
	int				j;
	int				ret;
	t_llderi		*tmp;

	tmp = (t_llderi *)g_llderi.buff;
	if (rule.d_size > 1 && ft_utils_isnullvalue(rule.deri))
		return (-1); // Erreur sur la grammaire
	i = 0;
	ret = 1;
	while (i < rule.d_size)
	{
		if(ft_lltab_insertterm(rule.deri[i], y, ind))
			break;
		j = 0;
		while (j < g_llpiv)
		{
			if (tmp[j].y == rule.deri[i] && rule.deri[i] != y)
			{
				ret = ft_lltab_initfirst(tmp[j], tmp[j].y, j);
				ft_utils_insert(g_llfirst.arr[ind], g_llffirst.arr[rule.deri[i] - 1], g_llfirst.max_x);
				ft_utils_insert(g_llffirst.arr[y - 1], g_llffirst.arr[rule.deri[i] - 1], g_llfirst.max_x);
				if (!ft_utils_isnullvalue(g_llffirst.arr[y - 1]))
					break ;
			}
			j++;
		}
		i++;
	}
	return (ret);
}

extern int			ft_lltab_first(void)
{
	int				i;
	t_llderi		*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		if (ft_lltab_initfirst(tmp[i], tmp[i].y, i) < 0)
			return (-1);
		i++;
	}
	return (1);
}
// */
