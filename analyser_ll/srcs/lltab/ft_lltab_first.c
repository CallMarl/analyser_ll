/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:45:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/19 18:40:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

static void		ft_lltab_insertfirst(int *line, int rule)
{
	int				i;

	i = 0;
	while (line[i] != -1 && line[i] != rule) // Erreur invalid read possible
		i++;
	line[i] = rule;
}

static int			ft_lltab_initfirst_aux(int **first, t_llderi rule, int y)
{
	int				i;
	int				ret;
	t_llderi		*tmp;

	tmp = (t_llderi *)g_llderi.buff;
	ret = 1;
	if (rule.deri[0] == rule.y)
		return (-1); //Erreur de définition de la grammaire
	else if (rule.deri[0] < g_llpiv)
	{
		i = 0;
		while (i < g_llpiv && ret > 0)
		{
			if (rule.deri[0] == tmp[i].y)
				ret = ft_lltab_initfirst_aux(first, tmp[i], y);
			i++;
		}
	}
	else
	{
		ft_lltab_insertfirst(first[y], rule.deri[0]);
		ret = 1;;
	}
	return (ret);
}

extern int			ft_lltab_initfirst(int **first)
{
	int				i;
	t_llderi		*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		if (ft_lltab_initfirst_aux(first, tmp[i], tmp[i].y - 1) < 0)
			return (-1);
		i++;
	}
	return (1);
}
