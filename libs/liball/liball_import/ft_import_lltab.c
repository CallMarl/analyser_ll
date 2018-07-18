/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_lltab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:41:36 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 15:32:02 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "liball.h"

extern int			ft_import_lltab(t_buff *gmr, t_lltab *lltab, int *cr)
{
	int				x;
	int				y;
	int				i;
	int				j;

	ft_memcpy((void *)&x, &gmr->buff[0], sizeof(int));
	(*cr) += sizeof(int);
	ft_putnbr(x);
	ft_memcpy_x((void *)&y, &gmr->buff[*cr], sizeof(int));
	(*cr) += sizeof(int);
	if (ft_utils_alloclltab(lltab, y, x) == -1)
		return (-1);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_memcpy(&lltab->lltab[i][j], &gmr->buff[*cr], sizeof(int));
			(*cr) += sizeof(int);
			j++;
		}
		i++;	
	}
	return (0);
}
