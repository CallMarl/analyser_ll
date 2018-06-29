/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:03 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 16:56:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "analyser_ll.h"

extern void			ft_debug_rule(t_buff rule)
{
	t_rule			tmp;
	size_t			i;

	i = 0;
	while (i < rule.cr)
	{
		tmp = ((t_rule *)rule.buff)[i];
		ft_putstr("rule index : ");
		ft_putnbr(tmp.i);
		ft_putchar('\n');
		ft_putstr("rule : ");
		ft_putendl(tmp.rule);
		ft_putstr("derivation : ");
		ft_putendl(tmp.deri);
		i++;
	}
	ft_putchar('\n');
}
