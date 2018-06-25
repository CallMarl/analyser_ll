/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:45:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/25 16:45:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "analyser_ll.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;

extern int			ft_lltab_first(t_llderi rule, int y, int ind, int mid)
{
	int				i;
	int				ret;

	ft_putnbr(rule.i);
	if (rule.deri[0] == rule.y)
		return (-1); //Erreur de définition de la gammaire.
	else if (rule.deri[0] < mid)
	{
		i = 0;
		ret = 0;
		while (i < mid + 1 && ret >= 0)
		{
			if (rule.deri[0] == ((t_llderi *)g_llderi.buff)[i].y 
					&& (rule.deri[0] != ind))
				ret = ft_lltab_first(((t_llderi *)g_llderi.buff)[i], y, ind, mid);
			i++;
		}
		return (ret);
	}
	else if (rule.deri[0] >= mid)
	{
		g_lltab.lltab[y - 1][rule.deri[0] - mid] = ind;
		return (1);
	}
	return (1);
}
