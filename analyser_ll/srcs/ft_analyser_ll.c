/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:00:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/20 14:51:48 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "analyser_ll.h"
#include "libft.h"

static int			ft_analyser_ll_aux(char *gramma_file, char *output_file)
{
	t_buff			term;
	t_buff			rule;
	int			ret;

	(void)output_file;
	ret = 1;
	if (!(ft_buffinit(&term, FT_BUFF_SIZE, sizeof(t_term))))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0 && !(ft_buffinit(&rule, FT_BUFF_SIZE, sizeof(t_rule))))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0)
		ret = ft_parse_gramma(gramma_file, &term, &rule);
	if (ret >= 0)
		ret = ft_lltab_init(term, rule);
	if (ret < 0)
		ft_error(ret);
	//ft_export_value(t_buff term, t_buff rule);
	if (term.buff != 0)
		ft_memdel((void **)&term.buff);
	if (rule.buff != 0)
		ft_memdel((void **)&rule.buff);
	return (ret);
}

extern int			ft_analyser_ll(int argc, char **argv)
{
	if (argc == 3)
		ft_analyser_ll_aux(argv[argc - 2], argv[argc - 1]);
	else
		ft_error(CODE_ERR2); //display_usage
	return (0);
}
