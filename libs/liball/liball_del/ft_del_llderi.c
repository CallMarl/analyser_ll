/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_llderi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:23:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 18:23:25 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern void			ft_del_llderi(t_buff *llderi)
{
	size_t			i;
	size_t			y;
	t_llderi		*tmp;

	if (llderi != 0 && llderi->buff != 0)
	{
		i = 0;
		while (i < llderi->cr)
		{
			tmp = &((t_llderi *)llderi->buff)[i];
			ft_strdel(&tmp->rule);
			tmp->y = 0;
			y = 0;
			while (y < tmp->d_size)
				tmp->deri[y++] = 0;
			ft_memdel((void **)&tmp->deri);
			tmp->d_size = 0;
			i++;
		}
		ft_buffdel(llderi);
		llderi->cr = 0;
		llderi->b_size = 0;
		llderi->e_size = 0;
	}
}
