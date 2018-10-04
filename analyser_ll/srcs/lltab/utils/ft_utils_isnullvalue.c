/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_isnullvalue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:30:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 15:09:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int		g_lllast;

extern int		ft_utils_isnullvalue(int *line, int size)
{
	int			i;

	i = 0;
	while (i < size && line[i] != -1)
	{
		if (line[i] == g_lllast)
			return (1);
		i++;
	}
	return (0);
}


