/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 15:06:09 by pprikazs         ###   ########.fr       */
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
typedef struct s_intarr	t_intarr;

struct					s_rule
{
	int					i;
	char				*rule;
	char				*deri;
};

struct					s_intarr
{
	int					max_x;
	int					max_y;
	int					**arr;
};

t_intarr				*ft_alloc_intarr(int x, int y);
int						ft_analyser_ll(int argc, char **argv);
int						ft_export_value(char *output_file);
int						ft_export_llderi(int fd);
int						ft_export_lltab(int fd);
int						ft_export_llterm(int fd);
void 					ft_lltab_follow(void);
int						ft_lltab_first(void);
int						ft_lltab_init(void);
int						ft_parse_gramma(char *gramma_file, t_buff *llterm, t_buff *llderi, int *llpiv);
int						ft_parse_initderi(t_buff *llderi, t_buff *rule);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);
void					ft_utils_insert(int *line, int *value, size_t size);
void					ft_utils_insertnull(int *line);
int						ft_utils_isnullvalue(int *line, int size);
void					ft_utils_uninitarr(t_intarr *arr);
int						ft_utils_initarr(t_intarr *arr, int x, int y);
int						ft_utils_getnbrule(void);

/*
** Fonction pour le débug des structures
*/

void					ft_debug_analyser();
void					ft_debug_rule(t_buff rule);
void					ft_debug_intarr(t_intarr *arr);

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
