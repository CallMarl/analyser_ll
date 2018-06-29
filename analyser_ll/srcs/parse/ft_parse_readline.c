/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:08:21 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 17:03:40 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern int			ft_parse_readline(char *line, t_buff *term, t_buff *rule)
{
	static int		stat = 0;
	int				ret;

	ret = 1;
	if (!(ft_strcmp(line, DELIM_BLOCK)))
	{
		stat++;
		return (1);
	}
	if (stat > 2)
		return (CODE_ERR4); // Trop de block seulement 2 sont valident
	if (stat == 1)
		ret = ft_parse_readterm(line, term);
	else if (stat == 2)
		ret = ft_parse_readrule(line, rule);
	return (ret);
}
