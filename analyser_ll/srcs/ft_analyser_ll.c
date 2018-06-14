/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:00:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/14 16:11:56 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "analyser_ll.h"
#include "libft.h"

/*
static void			ft_lltab_init(t_buff term, t_buff nterm)
{
	(void)term;
	(void)nterm;
}
*/

extern int			ft_analyser_ll(char *gramma_file)
{
	t_buff			term;
	t_buff			rule;
	int			ret;

	ret = 1;
	if (!(ft_buffinit(&term, FT_BUFF_SIZE, sizeof(t_term))))
		ret = -1; //Alloc error
	if (!(ft_buffinit(&rule, FT_BUFF_SIZE, sizeof(t_rule))))
		ret = -1; //Alloc error
	if (ret > 0)
		ret = ft_parse_gramma(gramma_file, &term, &rule);
	if (ret < 0)
		ft_error(ret);
	//ft_export_value(t_buff term, t_buff rule);
	if (term.buff != 0)
		ft_memdel(term.buff);
	if (rule.buff != 0)
		ft_memdel(rule.buff);
	return (1);
}
