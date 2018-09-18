/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:00:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/18 22:40:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "analyser_ll.h"
#include "liball.h"
#include "libft.h"

extern t_buff		g_llterm;
extern t_buff		g_llderi;
extern int			g_llpiv;

static int			ft_analyser_ll_aux(char *gramma_file, char *output_file)
{
	int			ret;

	ret = 1;
	if (!(ft_buffinit(&g_llterm, FT_BUFF_SIZE, sizeof(t_llterm))))
		ret = CODE_ERR1; //Alloc error
	if (!(ft_buffinit(&g_llderi, FT_BUFF_SIZE, sizeof(t_llterm))))
		ret = CODE_ERR1; //Alloc error
	if (ret > 0)
		ret = ft_parse_gramma(gramma_file, &g_llterm, &g_llderi, &g_llpiv);
	if (ret >= 0)
		ret = ft_lltab_init();
	if (ret >= 0)
		ft_export_value(output_file);
	if (ret < 0)
		ft_error(ret);
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
