/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_addtermdef.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:49:24 by                   #+#    #+#             */
/*   Updated: 2018/07/24 18:08:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "liball.h"
#include "libft.h"

extern void		ft_utils_addtermdef(t_buff *term, size_t index, \
		int (*def)(char *token))
{
	if (index < term->cr)
		((t_llterm *)term->buff)[index].def = def;
}
