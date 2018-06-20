/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_readrules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:14:06 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/20 15:44:22 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

static void			ft_parse_insertrule(char *line, t_buff *rule, t_rule *cur)
{
	if (*line == '\0')
	{
		cur->rule = ft_strdup(((t_rule *)rule->buff)[rule->cr - 1].rule);
		cur->i = ((t_rule *)rule->buff)[rule->cr - 1].i;
	}
	else
	{
		cur->rule = ft_strdup(line);
		cur->i = ((t_rule *)rule->buff)[rule->cr - 1].i + 1;
	}
}

static int			ft_parse_rule(char *line, t_buff *rule, t_rule *cur)
{
	char			*sub;

	if (!(sub = ft_strstr(line, DELIM_DERIV)))
		return (CODE_ERR5); // Pas de dérivation pour cette règles
	sub[0] = '\0';
	sub[1] = '\0';
	sub = &sub[2];
	ft_strsanitize(line, " \t\r\v");
	if (*line == '\0' && ((t_rule *)rule->buff)[rule->cr - 1].rule == 0)
		return (CODE_ERR5); // Une règle :: est indiqué mais aucune dérivation ne suit
	ft_parse_insertrule(line, rule, cur);
	ft_strsanitize(sub, " \t\r\v");
	if (sub == '\0')
		return (CODE_ERR5); // Une dérivé est attendu
	cur->deri = ft_strdup(sub);
	if (cur->rule == 0 || cur->deri == 0)
		return (CODE_ERR1); // Alloc error
	ft_bzero(sub, ft_strlen(sub));
	return (1);
}

extern int			ft_parse_readrule(char *line, t_buff *rule)
{
	t_rule			cur;
	int				ret;

	cur.i = 0;
	if ((ret = ft_parse_rule(line, rule, &cur)) < 0)
		return (ret); // Erreur à l'initialisation
	if (!ft_buffinsert(rule, &cur, FT_BUFF_SIZE))
		return (CODE_ERR1); //Alloc Error;
	return (ret);
}
