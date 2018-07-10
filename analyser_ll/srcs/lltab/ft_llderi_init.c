/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llderi_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:48:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 14:01:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "liball.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;

static int			ft_llderi_setderi(char *deri, t_buff *rule)
{
	size_t			i;

	if (!(ft_strcmp(deri, "ε")))
		return (rule->cr + g_llterm.cr);
	i = 0;
	while (i < rule->cr)
	{
		if (!(ft_strcmp(deri, ((t_rule *)rule->buff)[i].rule)))
			return ((int)((t_rule *)rule->buff)[i].i);
		i++;
	}
	i = 0;
	while (i < g_llterm.cr)
	{
		if (!(ft_strcmp(deri, ((t_llterm *)g_llterm.buff)[i].term)))
			return ((int)(rule->cr + ((t_llterm *)g_llterm.buff)[i].i));
		i++;
	}
	return (CODE_ERR6); // Il existe un term dans les dérivation qui n'est ni un regle ni un terminal
}

static int			ft_llderi_initaux(t_rule *cur, t_buff *rule)
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
		if ((code = ft_llderi_setderi(deri[i], rule)) < 0)
			break ;
		tmp.deri[i++] = code;
	}
	ft_strarr_del(&deri);
	if (code < 0)
		return (code);
	tmp.y = cur->i;
	tmp.rule = ft_strdup(cur->rule);
	if (!ft_buffinsert(&g_llderi, (void *)&tmp, rule->cr))
		return (CODE_ERR1);
	return (0);
}

extern int			ft_llderi_init(t_buff *rule)
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
		if ((ret = ft_llderi_initaux(&((t_rule *)rule->buff)[i], rule)) < 0)
			return (ret);
		i++;
	}
	return (1);
}
