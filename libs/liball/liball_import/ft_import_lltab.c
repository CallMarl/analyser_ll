/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_lltab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:41:36 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/24 16:07:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "liball.h"
#include "private_liball.h"

extern int			ft_import_lltab(t_buff *gmr, t_lltab *lltab, int *cr)
{
	int				x;
	int				y;
	int				i;
	int				j;

	ft_memcpy((void *)&x, (void *)&((char *)gmr->buff)[0], sizeof(int));
	(*cr) += sizeof(int);
	ft_memcpy_x((void *)&y, (void *)&((char *)gmr->buff)[*cr], sizeof(int));
	(*cr) += sizeof(int);
	if (ft_utils_alloclltab(lltab, y, x) == -1)
		return (-1);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_memcpy(&lltab->lltab[i][j], (void *)&((char *)gmr->buff)[*cr], sizeof(int));
			(*cr) += sizeof(int);
			j++;
		}
		i++;	
	}
	return (0);
}
