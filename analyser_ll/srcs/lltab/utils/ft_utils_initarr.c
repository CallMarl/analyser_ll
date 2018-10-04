/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_initarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:27:18 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:28:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int			ft_utils_initarr(t_intarr *arr, int x, int y)
{
	int				i;
	int				j;

	arr->max_x = x;
	arr->max_y = y;
	if (!(arr->arr = (int **)ft_memalloc(sizeof(int *) * y)))
		return (0);
	i = 0;
	while (i < y)
	{
		if (!(arr->arr[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (0);
		j = 0;
		while (j < x + 1)
		{
			arr->arr[i][j] = -1;
			j++;
		}
		i++;
	}
	return (1);
}
