/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_alloclltab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:52:30 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 15:55:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern int			ft_utils_alloclltab(t_lltab *lltab, int y, int x)
{
	int				i;
	int				j;

	if (!(lltab->lltab = (int **)ft_memalloc(sizeof(int *) * y)))
		return (-1);
	i = 0;
	while (i < y)
	{
		if (!(lltab->lltab[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (-1);
		j = 0;
		while (j < x + 1)
		{
			lltab->lltab[i][j] = -1;
			j++;
		}
		i++;
	}
	lltab->max_y = y;
	lltab->max_x = x;
	return (1);
}
