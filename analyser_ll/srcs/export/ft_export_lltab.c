/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_lltab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:46:57 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 17:16:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "analyser_ll.h"
# include "liball.h"

extern t_lltab 		g_lltab;

extern int			ft_export_lltab(int fd)
{
	int				i;
	int				j;

	ft_putnbr(g_lltab.max_x);
	ft_putendl("");
	ft_putnbr(g_lltab.max_y);
	write(fd, &g_lltab.max_x, sizeof(int));
	write(fd, &g_lltab.max_y, sizeof(int));
	i = 0;
	while (i < g_lltab.max_y)
	{
		j = 0;
		while (j < g_lltab.max_x)
		{
			write(fd, &g_lltab.lltab[i][j], sizeof(int));
			j++;
		}
		i++;
	}
	return (0);
}
