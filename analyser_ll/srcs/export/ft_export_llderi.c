/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_llderi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:30:36 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 17:11:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "analyser_ll.h"
#include "liball.h"
#include "libft.h"

extern t_buff		g_llderi;

static void			ft_export_llderi_aux(int fd, t_llderi llderi)
{
	size_t			len;
	size_t			i;

	len = 0;
	if (llderi.deri != 0)
		len = ft_strlen(llderi.rule);
	write(fd, &len, sizeof(size_t));
	i = 0;
	while (i < len)
	{
		write(fd, &llderi.rule[i], sizeof(char));
		i++;
	}
	write(fd, &llderi.y, sizeof(int));
	write(fd, &llderi.d_size, sizeof(size_t));
	i = 0;
	while (i < llderi.d_size)
	{
		write(fd, &llderi.deri[i], sizeof(int));
		i++;
	}
}

extern int			ft_export_llderi(int fd)
{
	size_t			i;

	write(fd, &g_llderi.cr, sizeof(size_t));
	write(fd, &g_llderi.e_size, sizeof(size_t));
	write(fd, &g_llderi.b_size, sizeof(size_t));
	i = 0;
	while (i < g_llderi.cr)
	{
		ft_export_llderi_aux(fd, ((t_llderi *)g_llderi.buff)[i]);
		i++;
	}
	return (0);
}
