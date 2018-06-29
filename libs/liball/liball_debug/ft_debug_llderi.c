/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_llderi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:48:34 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 16:56:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern void			ft_debug_llderi(t_buff llderi)
{
	size_t			i;
	size_t			j;
	t_llderi		*tmp;

	tmp = (t_llderi *)llderi.buff;
	i = 0;
	while (i < llderi.cr)
	{
		ft_putstr("\nderi rule : ");
		ft_putstr(tmp[i].rule);
		ft_putstr("\nderi index : ");
		ft_putnbr(tmp[i].y);
		ft_putstr("\nnb vals : ");
		ft_putnbr(tmp[i].d_size);
		ft_putstr("\nderi vals : ");
		j = 0;
		while (j < tmp[i].d_size)
		{
			(j == 0) ? ft_putstr("{") : ft_putstr(", ");
			ft_putnbr((int)(tmp[i].deri[j]));
			j++;
			if (j == tmp[i].d_size)
				ft_putendl("}\n");
		}
		i++;
	}
	ft_putchar('\n');
}
