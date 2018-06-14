/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_readrules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:14:06 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/14 17:14:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

static int			ft_parse_rule(char *line, t_buff *rule, t_rule *cur)
{
	char			*sub;

	if (!(sub = ft_strstr(line, DELIM_DERIV)))
		return (-1); // No dérivation for the rule
	sub[0] = '\0';
	sub[1] = '\0';
	sub = &sub[2];
	ft_strsanitize(line, " \t\r\v");
	if (line != '\0' && ((t_rule *)rule->buff)[rule->cr - 1].rule == 0)
		return (-1); // Try to get dérivation but not rule is set
	else if (line == '\0')
		cur->rule = ft_strdup(((t_rule *)rule->buff)[rule->cr - 1].rule);
	else
		cur->rule = ft_strdup(line);
	ft_strsanitize(sub, " \t\r\v");
	if (sub == '\0')
		return (-1); // Une dérivé est attendu
	cur->deri = ft_strdup(sub);
	if (cur->rule == 0 || cur->deri == 0)
		return (-1); // Alloc error
	ft_bzero(sub, ft_strlen(sub));
	return (1);
}

extern int			ft_parse_readrule(char *line, t_buff *rule)
{
	t_rule			cur;
	int				ret;

	if ((ret = ft_parse_rule(line, rule, &cur)) < 0)
		return (ret); // Erreur à l'initialisation
	if (!ft_buffinsert(rule, &cur, FT_BUFF_SIZE))
		return (-1); //Alloc Error;
	return (ret);
}
