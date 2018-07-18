/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_llterm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:24:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 18:27:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"

extern void			ft_del_llterm(t_buff *llterm)
{
	size_t			i;
	t_llterm		*tmp;

	if (llterm != 0 && llterm->buff != 0)
	{
		i = 0;
		while (i < llterm->cr)
		{
			tmp = &((t_llterm *)llterm->buff)[i];
			ft_strdel(&tmp->term);
			tmp->i = 0;
			i++;
		}
		ft_buffdel(llterm);
		llterm->cr = 0;
		llterm->b_size = 0;
		llterm->e_size = 0;
	}
}
