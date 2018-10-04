/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:29:19 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:37:26 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern int		g_lllast;
extern int		g_llpiv;

extern void		ft_utils_insert(int *line, int *value, size_t size)
{
	size_t			i;
	int				j;
	int				x;

	i = 0;
	x = g_lllast - g_llpiv + 1;
	while (i < size && value[i] != -1)
	{
		j = 0;
		if (value[i] != g_lllast)
		{
			while (j < x && line[j] != value[i] && line[j] != -1)
				j++;
			line[j] = value[i];
		}
		i++;
	}
}


