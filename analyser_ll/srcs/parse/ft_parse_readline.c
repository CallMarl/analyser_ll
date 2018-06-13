/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:08:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/13 16:12:16 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int			ft_parse_readline(char *line, t_buff *term, t_buff *rule)
{
	static int		stat = 0;
	int				ret;

	if (!(ft_strcmp(line, BLOCK_DELIM)))
	{
		stat++;
		return (1);
	}
	if (stat > 2)
		return (-2) // Trop de block seulement 2 sont valident
	if (stat == 1)
	{
		if ((ret = ft_parse_readterm(line, term)) < 0)
			return (ret);
	}
	else if (stat == 2)
	{
		if ((ret = ft_parse_readterm(line, rule)) < 0)
			return (ret);
	}
	return (1);
}

