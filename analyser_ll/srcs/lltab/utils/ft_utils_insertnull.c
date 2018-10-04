/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_insertnull.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:29:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 13:37:54 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int		g_lllast;
extern int		g_llpiv;

extern void		ft_utils_insertnull(int *line)

{
	int			i;
	int			x;
	
	i = 0;
	x = g_lllast - g_llpiv + 1;
	while (i < x && line[i] != g_lllast && line[i] != -1)
		i++;
	line[i] = g_lllast;
}
