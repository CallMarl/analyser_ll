/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_readterm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:11:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/14 17:17:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

static int			ft_parse_readterm_aux(t_buff *term, char **arr)
{
	size_t			i;
	t_term			tmp;
	int				ret;

	i = 0;
	ret = 1;
	while (ret > 0 && arr[i] != 0)
	{
		if (!(tmp.term = ft_strdup(arr[i])))
			ret = -1; //Alloc error
		else
		{
			tmp.i = term->cr;
			if (!ft_buffinsert(term, &tmp, FT_BUFF_SIZE))
				ret = -2; //Alloc error
		}
	}
	if (ret == -2)
	{
		ft_strdel(&tmp.term);
		ret = -1;
	}
	return (ret);
}

extern int			ft_parse_readterm(char *line, t_buff *term)
{
	char			**arr;

	if (!(arr = ft_strexplode(line, " \t\r\v")))
		return (-1); //Alloc Error
//	if (!ft_strisalnum(line))
//		return (-3); // Les terminaux ne peuvent etre composé que de caractere alnum
	if (ft_parse_readterm_aux(term, arr) < 0)
		return (-1); // Alloc Error
	ft_strarr_del(&arr);
	return (1);
}
