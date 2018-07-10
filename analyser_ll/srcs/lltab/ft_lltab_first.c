/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:45:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 14:24:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

extern int			ft_lltab_first(t_llderi rule, int y, int ind)
{
	int				i;
	int				ret;

	ret = 0;
	if (rule.deri[0] == y)
		return (-1); //Erreur de définition de la gammaire.
	else if (rule.deri[0] < g_llpiv)
	{
		i = 0;
		while (i < g_llpiv && ret >= 0)
		{
			if (rule.deri[0] == ((t_llderi *)g_llderi.buff)[i].y 
					&& (rule.deri[0] != ind && rule.deri[0] != rule.y))
				ret = ft_lltab_first(((t_llderi *)g_llderi.buff)[i], y, ind);
			i++;
		}
	}
	else if (rule.deri[0] >= g_llpiv)
	{
		g_lltab.lltab[y - 1][rule.deri[0] - g_llpiv] = ind;
		return (1);
	}
	return (ret);
}
