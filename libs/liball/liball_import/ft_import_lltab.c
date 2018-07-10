/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_lltab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:41:36 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 17:22:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "liball.h"

extern int			ft_import_lltab(int fd, t_lltab *lltab)
{
	int				x;
	int				y;
	int				i;
	int				j;

	read(fd, (void *)&x, sizeof(int));
	read(fd, (void *)&y, sizeof(int));
	ft_putnbr(x);
	ft_putendl("");
	ft_putnbr(y);
	ft_putendl("");
	if (ft_utils_alloclltab(lltab, y, x) == -1)
		return (-1);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			read(fd, &lltab->lltab[i][j], sizeof(int));
			j++;
		}
		i++;	
	}
	return (0);
}
