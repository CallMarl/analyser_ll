/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/14 16:19:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSER_LL_H
# define ANALYSER_LL_H

# define DELIM_BLOCK "%%"
# define DELIM_DERIV "::"

#include "libft.h"

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
	char				*deri;
};

int						ft_analyser_ll(char *gramma_file);
void					ft_error(int err_code);
void					ft_debug_rule(t_buff *rule);
void					ft_debug_term(t_buff *term);
int						ft_parse_gramma(char *gramma_file, t_buff *term, t_buff *nterm);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);

#endif
