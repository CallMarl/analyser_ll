/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_gramma.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:05:08 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/20 12:54:14 by pprikazs         ###   ########.fr       */
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

static int			ft_parse_gramma_aux(int fd, t_buff *term, t_buff *rule)
{
	char			*line;
	int				ret;

	line = 0;
	ret = 0;
	while (ret >= 0 && (ret = ft_gnl(fd, &line)) >= 1)
	{
		ft_strsanitize(line, " \t\v\r");
		if (*line != '\0')
			ret = ft_parse_readline(line, term, rule);
		ft_strdel(&line);
	}
	return (ret);
}

extern int			ft_parse_gramma(char *gramma_file, t_buff *llterm, t_buff *llderi, int *llpiv)
{
	int				fd;
	int				ret;
	t_buff			rule;

	ret = 0;
	if (!ft_parser_checkext(gramma_file, INPUT_EXT))
		return (CODE_ERR3); //Bad input file ext
	fd = open(gramma_file, O_RDONLY);
	if (!(ft_buffinit(&rule, FT_BUFF_SIZE, sizeof(t_rule))))
		return (CODE_ERR1); //Alloc error
	if ((ret = ft_parse_gramma_aux(fd, llterm, &rule)) < 0)
		return (ret);	
	ft_parse_initderi(llderi, &rule);
	*llpiv = rule.cr;
	if (rule.buff != 0)
		ft_memdel((void **)&rule.buff);
	close(fd);
	return (ret);
}
