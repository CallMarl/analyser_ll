/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:32:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/27 17:57:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;

static int			ft_format_dericode(char *deri, t_buff *rule, t_buff *term)
{
	size_t			i;

	if (!(ft_strcmp(deri, "ε")))
		return (rule->cr + term->cr - 1);
	i = 0;
	while (i < rule->cr)
	{
		if (!(ft_strcmp(deri, ((t_rule *)rule->buff)[i].rule)))
			return ((int)((t_rule *)rule->buff)[i].i);
		i++;
	}
	i = 0;
	while (i < term->cr)
	{
		if (!(ft_strcmp(deri, ((t_term *)term->buff)[i].term)))
			return ((int)(rule->cr - 1 + ((t_term *)term->buff)[i].i));
		i++;
	}
	return (-5); // Il existe un term dans les dérivation qui n'est ni un regle ni un terminal
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

static int			ft_lltab_alloc(int y, int x)
{
	int				i;
	int				j;

	if (!(g_lltab.lltab = (int **)ft_memalloc(sizeof(int *) * y)))
		return (CODE_ERR1);
	i = 0;
	while (i < y)
	{
		if (!(g_lltab.lltab[i] = (int *)ft_memalloc(sizeof(int) * x + 1)))
			return (CODE_ERR1);
		j = 0;
		while (j < x + 1)
		{
			g_lltab.lltab[i][j] = -1;
			j++;
		}
		i++;
	}
	g_lltab.max_y = y;
	g_lltab.max_x = x + 1;
	ft_debug_lltab();
	return (1);
}

extern int			ft_lltab_init(t_buff rule, t_buff term)
{
	int				ret;
	size_t			i;

	ft_debug_rule(rule);
	ft_putchar('\n');
	ft_debug_term(term);
	ret = ft_format_deri(&rule, &term);
	if (ret > 0)
		ret = ft_lltab_alloc(rule.cr, term.cr);
	if (ret > 0)
	{
		ft_debug_deri();
		ft_debug_term(term);
		i = 0;
		while (i < rule.cr)
		{
			ft_lltab_first(((t_llderi *)g_llderi.buff)[i], \
					((t_llderi *)g_llderi.buff)[i].y , i, rule.cr - 1);
			i++;
		}
		i = 0;
		ft_debug_lltab();
		while (i < rule.cr)
		{
			if (ft_lltab_eps(((t_llderi *)g_llderi.buff)[i], rule.cr - 1) == 1)
			{
				ft_lltab_follow(((t_llderi *)g_llderi.buff)[i], \
					((t_llderi *)g_llderi.buff)[i].y, i, rule.cr);
			}
			i++;
		}
		ft_debug_lltab();
	}
	return (ret);
}
