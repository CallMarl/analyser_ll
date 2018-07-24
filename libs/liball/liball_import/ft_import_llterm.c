/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_llterm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:17:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/24 16:08:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "libft.h"
#include "liball.h"

static int			ft_import_llterm_aux(t_buff *gmr, t_llterm *term, int *cr)
{
	size_t			len;

	ft_memcpy(&term->i, (void *)&((char *)gmr->buff)[*cr], sizeof(int));
	(*cr) += sizeof(int);
	ft_memcpy(&len, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	if (!(term->term = ft_strnew(len)))
		return (-1);
	ft_memcpy(term->term, (void *)&((char *)gmr->buff)[*cr], sizeof(char) * len);
	(*cr) += sizeof(char) * len;	
	return (0);
}

extern int			ft_import_llterm(t_buff *gmr, t_buff *llterm, int *cr)
{
	size_t			i;

	ft_memcpy(&llterm->cr, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	ft_memcpy(&llterm->e_size, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	ft_memcpy(&llterm->b_size, (void *)&((char *)gmr->buff)[*cr], sizeof(size_t));
	(*cr) += sizeof(size_t);
	llterm->b_size = llterm->cr;
	llterm->cr = 0;
	if (!(llterm->buff = (t_llterm *)ft_memalloc(llterm->e_size * llterm->b_size)))
		return (-1);
	i = 0;
	while (i < llterm->b_size)
	{
		if ((ft_import_llterm_aux(gmr, &((t_llterm *)llterm->buff)[i], cr)) == -1)
			return (-1);
		else
			(llterm->cr)++;
		i++;
	}
	return (0);
}
