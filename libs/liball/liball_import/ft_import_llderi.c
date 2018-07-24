/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_llderi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:14:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/24 16:02:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include "liball.h"

static int			ft_import_llderi_aux(t_buff *gmr, t_llderi *deri, int *cr)
{
	size_t			len;
	size_t			i;

	ft_memcpy((void *)&len, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	if (!(deri->rule = ft_strnew(len)))
		return (-1);
	ft_memcpy((void *)deri->rule, (void *)&((char *)gmr->buff)[*cr], sizeof(char) * len);
	(*cr) += sizeof(char) * len;
	ft_memcpy((void *)&deri->y, (void *)&((char *)gmr->buff)[*cr], sizeof(int));
	(*cr) += sizeof(int);
	ft_memcpy_x((void *)&deri->d_size, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	if (!(deri->deri = (int *)ft_memalloc(sizeof(int) * deri->d_size)))
		return (-1);
	i = 0;
	while (i < deri->d_size)
	{
		ft_memcpy((void *)&deri->deri[i], (void *)&((char *)gmr->buff)[*cr], sizeof(int));
		(*cr) += sizeof(int);
		i++;
	}
	return (0);
}

extern int			ft_import_llderi(t_buff *gmr, t_buff *llderi, int *cr)
{
	size_t			i;

	ft_memcpy(&llderi->cr, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	ft_memcpy(&llderi->e_size, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	ft_memcpy(&llderi->b_size, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	llderi->b_size = llderi->cr;
	llderi->cr = 0;
	if (!(llderi->buff = ft_memalloc(llderi->e_size * llderi->b_size)))
		return (-1);
	i = 0;
	while (i < llderi->b_size)
	{
		if (ft_import_llderi_aux(gmr, &((t_llderi *)llderi->buff)[i], cr) == -1)
			return (-1);
		else
			(llderi->cr)++;
		i++;
	}
	return (0);
}
