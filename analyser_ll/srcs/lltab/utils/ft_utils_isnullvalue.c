/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_isnullvalue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:30:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:38:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int		g_lllast;
extern int		g_llpiv;

extern int		ft_utils_isnullvalue(int *line)
{
	int			i;
	int			x;

	i = 0;
	x = g_lllast - g_llpiv + 1;
	while (i < x && line[i] != -1)
	{
		if (line[i] == g_lllast)
			return (1);
		i++;
	}
	return (0);
}


