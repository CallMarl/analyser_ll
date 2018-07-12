/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_llderi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:14:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 17:47:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include "liball.h"

static int			ft_import_llderi_aux(int fd, t_llderi *deri)
{
	size_t			len;
	size_t			i;

	read(fd, &len, sizeof(size_t));
	if (!(deri->rule = ft_strnew(len)))
		return (-1);
	read(fd, deri->rule, sizeof(char) * len);
	read(fd, &deri->y, sizeof(int));
	read(fd, &deri->d_size, sizeof(size_t));
	if (!(deri->deri = (int *)ft_memalloc(sizeof(int) * deri->d_size)))
		return (-1);
	i = 0;
	while (i < deri->d_size)
	{
		read(fd, &deri->deri[i], sizeof(int));
		i++;
	}
	return (0);
}

extern int			ft_import_llderi(int fd, t_buff *llderi)
{
	size_t			i;

	read(fd, &llderi->cr, sizeof(size_t));
	read(fd, &llderi->e_size, sizeof(size_t));
	read(fd, &llderi->b_size, sizeof(size_t));
	llderi->b_size = llderi->cr;
	if (!(llderi->buff = ft_memalloc(llderi->e_size * llderi->cr)))
		return (-1);
	i = 0;
	while (i < llderi->cr)
	{
		if (ft_import_llderi_aux(fd, &((t_llderi *)llderi->buff)[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
