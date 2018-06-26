/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_eps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:06:27 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/26 15:18:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;

extern int			ft_lltab_eps(t_llderi rule, int mid)
{
	size_t			i;

	i = 0;
	while (i < rule.d_size)
	{
		if (mid <= rule.deri[i] && rule.deri[i] < mid + g_lltab.max_x)
			return (0);
		else if (rule.deri[i] < mid)
		{
			if (g_lltab.lltab[((t_llderi *)g_llderi.buff)[rule.deri[i]].y][g_lltab.max_x - 1] == -1)
				return (0);
		}
		i++;
	}
	return (1);
}
