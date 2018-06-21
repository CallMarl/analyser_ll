/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/21 16:04:01 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;

static int			ft_format_dericode(char *deri, t_buff *rule, t_buff *term)
{
	size_t			i;

	if (!(ft_strcmp(deri, "ε")))
		return (rule->cr + term->cr + 1);
	i = 0;
	while (i < rule->cr)
	{
		if (!(ft_strcmp(deri, ((t_rule *)rule->buff)[i].rule)))
			return ((int)i);
		i++;
	}
	i = 0;
	while (i < term->cr)
	{
		if (!(ft_strcmp(deri, ((t_term *)term->buff)[i].term)))
			return ((int)(rule->cr + i));
		i++;
	}
	return (-1); // Il existe un term dans les dérivation qui n'est ni un regle ni un terminal
}

static int			ft_format_setderi(t_rule *cur, t_buff *rule, \
		t_buff *term, int y)
{
	char			**deri;
	t_llderi		tmp;
	size_t			i;
	int				code;

	if (!(deri = ft_strexplode(cur->deri, " \t\r\v")))
		return (CODE_ERR1);
	tmp.d_size = ft_strarr_size(deri);
	if (!(tmp.deri = (int *)ft_memalloc(sizeof(int) * tmp.d_size)))
		return (CODE_ERR1);
	i = 0;
	while (deri[i] != 0)
	{
		if ((code = ft_format_dericode(deri[i], rule, term)) < 0)
			break ;
		tmp.deri[i++] = code;
	}
	ft_strarr_del(&deri);
	if (code < 0)
		return (code);
	tmp.i = y;
	tmp.y = cur->i;
	if (!ft_buffinsert(&g_llderi, (void *)&tmp, rule->cr))
		return (CODE_ERR1);
	return (0);
}

static int			ft_format_deri(t_buff *rule, t_buff *term)
{
	size_t			i;
	int				ret;

	if (g_llderi.buff == 0)
	{
		if (!(ft_buffinit(&g_llderi, rule->cr, sizeof(t_llderi))))
			return (CODE_ERR1);
	}
	i = 0;
	while (i < rule->cr)
	{
		if ((ret = ft_format_setderi(&((t_rule *)rule->buff)[i], rule, term, i)) < 0)
			return (ret);
		i++;
	}
	return (1);
}

extern int			ft_lltab_init(t_buff rule, t_buff term)
{
	int				ret;

	//ft_debug_term(term);
	//ft_putchar('\n');
	ft_debug_rule(rule);
	ret = ft_format_deri(&rule, &term);
	ft_debug_deri();
	return (ret);
}
