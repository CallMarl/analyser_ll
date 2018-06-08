/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:00:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/08 19:50:02 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types>

static int			ft_parse_readline(char *line, t_buff *term, t_buff *nterm)
{
	(void)line;
	(void)term;
	(void)nterm;
}

static int			ft_parse_gramma(char *gramm_file, t_buff *term, t_buff *nterm)
{
	FILE		*fd;
	char		*line;
	int			ret;

	fd = open(gramma_file, O_RDONLY);
	line = 0;
	ret = 0;
	while (ret >= 0 && ret = ft_gnl(fd, &line) >= 1)
	{
		line = ft_strsanitize(line, " \t\v\r");
		if (*line != '\0')
			ft_parse_readline(line);
		ft_strdel(line);
	}
	return (ret);
}

static void			ft_init_lltab(t_buff term, t_buff nterm)
{
	(void)term;
	(void)nterm;
}

extern int			ft_analyser_ll(char *gramma_file)
{
	t_buff			term;
	t_buff			nterm;
	int			ret;

	//Initialiser les buffer
	ret = ft_parse_gramma(gramma_line, &term, &nterm);
	if (ret < 0)
		ft_error(ret);
	ft_export_value(t_buff term, t_buff nterm);
	return (1);
}
