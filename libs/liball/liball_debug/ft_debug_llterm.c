/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_llterm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:50:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 17:32:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "liball.h"
#include "libft.h"

/*
** Bien que non présent dans le display de ce debugging le caractere `ε`
** est implicitement inclut dans le table d'analyse ll.
*/

extern void			ft_debug_llterm(t_buff llterm)
{
	t_llterm		tmp;
	size_t			i;

	i = 0;
	while (i < llterm.cr)
	{
		tmp = ((t_llterm *)llterm.buff)[i];
		ft_putstr("term : ");
		ft_putendl(tmp.term);
		i++;
	}
	ft_putchar('\n');
}
