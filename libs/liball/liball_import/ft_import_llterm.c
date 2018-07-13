/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_llterm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:17:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/13 10:33:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "libft.h"
#include "liball.h"

static int			ft_import_llterm_aux(int fd, t_llterm *term)
{
	size_t			len;

	read(fd, &term->i, sizeof(int));
	read(fd, &len, sizeof(size_t));
	if (!(term->term = ft_strnew(len)))
		return (-1);
	read(fd, term->term, sizeof(char) * len);
	return (0);
}

extern int			ft_import_llterm(int fd, t_buff *llterm)
{
	size_t			i;

	read(fd, &llterm->cr, sizeof(size_t));
	read(fd, &llterm->e_size, sizeof(size_t));
	read(fd, &llterm->b_size, sizeof(size_t));
	if (!(llterm->buff = (t_llterm *)ft_memalloc(llterm->e_size * llterm->cr)))
		return (-1);
	i = 0;
	while (i < llterm->cr)
	{
		if ((ft_import_llterm_aux(fd, &((t_llterm *)llterm->buff)[i])) == -1)
			return (-1);
		i++;
	}
	return (0);
}
