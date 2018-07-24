/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_addtermtoken.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:51:35 by                   #+#    #+#             */
/*   Updated: 2018/07/24 18:27:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "liball.h"
#include "libft.h"

extern void		ft_utils_addtermtoken(t_buff *term, size_t index, \
		char *token)
{
	if (index < term->cr)
		((t_llterm *)term->buff)[index].token = token;
}
