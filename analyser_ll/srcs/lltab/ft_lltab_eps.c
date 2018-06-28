/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_eps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:06:27 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/28 16:12:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

extern int			ft_lltab_eps(t_llderi rule)
{
	size_t			i;

	i = 0;
	while (i < rule.d_size)
	{
		if (g_llpiv <= rule.deri[i] && rule.deri[i] < g_llpiv + g_lltab.max_x - 1)
			return (0);
		else if (rule.deri[i] < g_llpiv)
		{
			
			if (g_lltab.lltab[((t_llderi *)g_llderi.buff)[rule.deri[i]].y][g_lltab.max_x - 1])
				return (0);
		}
		i++;
	}
	return (1);
}
