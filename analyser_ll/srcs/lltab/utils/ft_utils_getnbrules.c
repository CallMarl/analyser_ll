/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_getnbrules.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:25:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:36:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;

extern int			ft_utils_getnbrule(void)
{
	size_t			i;
	int				nb;
	t_llderi		tmp;

	i = 0;
	nb = -1;
	while (i < g_llderi.cr)
	{
		tmp = ((t_llderi *)g_llderi.buff)[i];
		nb = (nb < tmp.y) ? tmp.y : nb;
		i++;
	}
	return (nb);
}

