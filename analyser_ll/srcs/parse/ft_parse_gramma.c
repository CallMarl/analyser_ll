/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_gramma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:05:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/13 16:10:14 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "analyser_ll.h"
#include "libft.h"

extern int			ft_parse_gramma(char *gramm_file, t_buff *term, t_buff *nterm)
{
	int			*fd;
	char		*line;
	int			ret;

	fd = open(gramma_file, O_RDONLY);
	line = 0;
	ret = 0;
	while (ret >= 0 && ret = ft_gnl(fd, &line) >= 1)
	{
		line = ft_strsanitize(line, " \t\v\r");
		if (*line != '\0')
			ret = ft_parse_readline(line);
		ft_strdel(line);
	}
	close(fd);
	return (ret);
}
