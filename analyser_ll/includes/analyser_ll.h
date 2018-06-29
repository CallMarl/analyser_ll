/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 17:25:38 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSER_LL_H
# define ANALYSER_LL_H

# include "libft.h"
# include "liball.h"

/*
** Analyser_ll
*/

# define INPUT_EXT ".gmr"
# define OUTPUT_EXT ".all"
# define DELIM_BLOCK "%%"
# define DELIM_DERIV "::"

typedef struct s_rule	t_rule;

struct					s_rule
{
	int					i;
	char				*rule;
	char				*deri;
};

int						ft_analyser_ll(int argc, char **argv);
int						ft_export_value(char *output_file);
int						ft_llderi_init(t_buff *rule);
int						ft_lltab_eps(t_llderi rule);
int						ft_lltab_first(t_llderi rule, int y, int ind);
int						ft_lltab_follow(t_llderi rule, int y, int ind);
int						ft_lltab_init(t_buff rule);
int						ft_parse_gramma(char *gramma_file, t_buff *term, t_buff *rule);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);

/*
** Fonction pour le débug des structures
*/

void					ft_debug_rule(t_buff rule);

/*
** Gesion des erreur
*/

# define CODE_ERR1 -1
# define CODE_ERR2 -2
# define CODE_ERR3 -3
# define CODE_ERR4 -4
# define CODE_ERR5 -5

# define MESS_ERR1 "Erreur d'allocation."
# define MESS_ERR2 "Mauvaise usage."
# define MESS_ERR3 "Mauvaise extension pour le fichier d'entré."
# define MESS_ERR4 "Seulement 2 bloques peuvent être définit dans un fichier de grammaire."
# define MESS_ERR5 "Une règle est définit mais aucune dérivation lui est spécifié."

void					ft_error(int err_code);


#endif
