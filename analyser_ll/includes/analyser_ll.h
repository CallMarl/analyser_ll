/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/13 16:21:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSER_LL_H
# define ANALYSER_LL_H

# define BLOCK_DELIM "%%"

typedef struct s_term	t_term;
typedef struct s_rule	t_rule;

struct					s_term
{
	int					i;
	char				*term;
};

struct					s_rule
{
	int					i;
	char				*rule;
	char				**deri;
};

int						ft_analyser_ll(char *gramma_file);
int						ft_parse_gramma(char *gramma_file, t_buff *term, t_buff *nterm);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);

#endif
