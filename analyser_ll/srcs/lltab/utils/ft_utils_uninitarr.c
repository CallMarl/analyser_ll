/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_uninitarr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:28:10 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:28:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern void			ft_utils_uninitarr(t_intarr *arr)
{
	int				i;

	if (arr->arr != 0)
	{
		i = 0;
		while (arr->arr[i] != 0 && i < arr->max_y)
			ft_memdel((void **)&(arr->arr[i++]));
		ft_memdel((void **)&(arr->arr));
	}
	arr->max_x = 0;
	arr->max_y = 0;
}


