/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyser_ll.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:00:12 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/10 17:41:54 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types>

#define BLOCK_DELIM "%%"

typedef	struct		s_term
{
	int				i;
	char			*term;
}					t_term

typedef struct		s_rule
{
	int				i;
	char			*rule;
	char			**deri;
}

static void			ft_init_lltab(t_buff term, t_buff nterm)
{
	(void)term;
	(void)nterm;
}

static int			ft_parse_readrule(char *line, t_buff *rule)
{

}

static int			ft_parse_readterm_aux(char *line, t_buff *term, char **arr)
{
	size_t			i;
	t_term			tmp;
	int				ret;

	i = 0;
	ret = 1;
	while (ret > 0 && arr[i] != 0)
	{
		if (!(tmp.term = ft_strdup(arr[i])))
			ret = -1; //Alloc error
		else
		{
			tmp.i = term->cr;
			if (!ft_buffinsert(term, &tmp, FT_BUFF_SIZE))
				ret = -2; //Alloc error
		}
	}
	if (ret == -2)
	{
		ft_strdel(&tmp.term);
		ret = -1;
	}
	return (ret);
}

static int			ft_parse_readterm(char *line, t_buff *term)
{
	char			**arr;

	if (!(arr = ft_strexplode(line, " \t\r\v")))
		return (-1) //Alloc Error
	if (!ft_strisalnum(line))
		return (-3) // Les terminaux ne peuvent etre composé que de caractere alnum
	if (ft_parse_readterm_aux(line, term, arr) < 0)
		return (-1) // Alloc Error
	ft_strarr_del(&arr);
	return (ret);
}

static int			ft_parse_readline(char *line, t_buff *term, t_buff *rule)
{
	static int		stat = 0;
	int				ret;

	if (!(ft_strcmp(line, BLOCK_DELIM)))
	{
		stat++;
		return (1);
	}
	if (stat > 2)
		return (-2) // Trop de block seulement 2 sont valident
	if (stat == 1)
	{
		if ((ret = ft_parse_readterm(line, term)) < 0)
			return (ret);
	}
	else if (stat == 2)
	{
		if ((ret = ft_parse_readterm(line, rule)) < 0)
			return (ret);
	}
	return (1);
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
			ret = ft_parse_readline(line);
		ft_strdel(line);
	}
	close(fd);
	return (ret);
}

extern int			ft_analyser_ll(char *gramma_file)
{
	t_buff			term;
	t_buff			rule;
	int			ret;

	ret = 1;
	if (!(term = ft_buffinit(&term, FT_BUFF_SIZE, sizeof(t_term))
		ret = -1; //Alloc error
	if (!(nterm = ft_buffinit(&rule, FT_BUFF_SIZE, sizeof(t_rule))
		ret = -1; //Alloc error
	if (ret > 0)
		ret = ft_parse_gramma(gramma_line, &term, &rule);
	if (ret < 0)
		ft_error(ret);
	ft_export_value(t_buff term, t_buff rule);
	if (term.buff != 0)
		ft_memdel(term.buff);
	if (nterm.buff != 0)
		ft_memdel(nterm.buff);
	return (1);
}
