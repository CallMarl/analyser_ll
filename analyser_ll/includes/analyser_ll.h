/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/19 18:45:14 by pprikazs         ###   ########.fr       */
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
int						ft_export_llderi(int fd);
int						ft_export_lltab(int fd);
int						ft_export_llterm(int fd);
void 					ft_lltab_initfollow(int **follow, int **first, int y);
int						ft_lltab_initfirst(int **first);
int						ft_lltab_getnbrule(void);
int						ft_lltab_init();
int						ft_parse_gramma(char *gramma_file, t_buff *llterm, t_buff *llderi, int *llpiv);
int						ft_parse_initderi(t_buff *llderi, t_buff *rule);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);

/*
** Fonction pour le débug des structures
*/

void					ft_debug_analyser();
void					ft_debug_rule(t_buff rule);
void					ft_debug_intarr(int **arr, int x, int y);

/*
** Gesion des erreur
*/

# define CODE_ERR1 -1
# define CODE_ERR2 -2
# define CODE_ERR3 -3
# define CODE_ERR4 -4
# define CODE_ERR5 -5
# define CODE_ERR6 -6

# define MESS_ERR1 "Erreur d'allocation."
# define MESS_ERR2 "Mauvaise usage."
# define MESS_ERR3 "Mauvaise extension pour le fichier d'entré."
# define MESS_ERR4 "Seulement 2 bloques peuvent être définit dans un fichier de grammaire."
# define MESS_ERR5 "Une règle est définit mais aucune dérivation lui est spécifié."
# define MESS_ERR6 "Il exist un term dans la grammaire qui n'est ni une regle ni un terminal"

void					ft_error(int err_code);


#endif
