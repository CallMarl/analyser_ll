/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_gramma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:05:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 17:04:49 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "analyser_ll.h"
#include "libft.h"

static int			ft_parser_checkext(char *gramma_file, char *ext)
{
	char 			*sub;

	sub = ext;
	while ((sub = ft_strstr(gramma_file, sub)) != 0)
	{
		if (!ft_strcmp(sub, ext))
			return (1);
	}
	return (0);
}

extern int			ft_parse_gramma(char *gramma_file, t_buff *term, t_buff *rule)
{
	int			fd;
	char		*line;
	int			ret;

	if (!ft_parser_checkext(gramma_file, INPUT_EXT))
		return (CODE_ERR3); //Bad input file ext
	fd = open(gramma_file, O_RDONLY);
	line = 0;
	ret = 0;
	while (ret >= 0 && (ret = ft_gnl(fd, &line)) >= 1)
	{
		ft_strsanitize(line, " \t\v\r");
		if (*line != '\0')
			ret = ft_parse_readline(line, term, rule);
		ft_strdel(&line);
	}
	close(fd);
	return (ret);
}
