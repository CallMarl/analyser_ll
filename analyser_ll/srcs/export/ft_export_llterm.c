/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_llterm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:00:27 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 17:46:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include "analyser_ll.h"

extern t_buff		g_llterm;

static void			ft_export_llterm_aux(int fd, t_llterm term)
{
	size_t			len;
	size_t			i;

	write(fd, &term.i, sizeof(int));
	len = 0;
	if (term.term != 0)
		len = ft_strlen(term.term);
	i = 0;
	write(fd, &len, sizeof(size_t));
	while (i < len)
	{
		write(fd, &term.term[i], sizeof(char));
		i++;
	}
}

extern int			ft_export_llterm(int fd)
{
	size_t			i;

	write(fd, &g_llterm.cr, sizeof(size_t));
	write(fd, &g_llterm.e_size, sizeof(size_t));
	write(fd, &g_llterm.b_size, sizeof(size_t));
	i = 0;
	while (i < g_llterm.cr)
	{
		ft_export_llterm_aux(fd, ((t_llterm *)g_llterm.buff)[i]);
		i++;
	}
	i = 0;
	return (0);
}
