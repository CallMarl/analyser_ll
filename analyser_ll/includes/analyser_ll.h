/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_ll.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:53 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/28 15:32:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSER_LL_H
# define ANALYSER_LL_H

# define INPUT_EXT ".gmr"
# define OUTPUT_EXT ".all"
# define DELIM_BLOCK "%%"
# define DELIM_DERIV "::"


#include "libft.h"

typedef struct s_term	t_term;
typedef struct s_rule	t_rule;
typedef struct s_lltab	t_lltab;
typedef struct s_llderi	t_llderi;

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


/*
** Structure pour la table d'analyse ll,
** Matrice cub de coordonnée x, y, z où 
** x définit l'ensemble des terminaux,
** y définit l'ensemble des règles
** et z valeur à la coordonnées [x, y], dérivation de la règle y par x
*/ 

struct					s_lltab
{
	int					max_x;
	int					max_y;
	int					**lltab;
};

/*
** i index de la dérivation
** y index de la regle dérivé
** taille du tableau de dérivation
** table des dérivation
*/

struct					s_llderi
{
	int					i;
	char				*rule;
	int					y;
	size_t				d_size;
	int					*deri;
};

int						ft_analyser_ll(int argc, char **argv);

/*
** Gesion des erreur
*/

#define	CODE_ERR1 -1
#define MESS_ERR1 "Erreur d'allocation."
#define	CODE_ERR2 -2
#define MESS_ERR2 "Mauvaise usage."
#define	CODE_ERR3 -3
#define MESS_ERR3 "Mauvaise extension pour le fichier d'entré."
#define	CODE_ERR4 -4
#define MESS_ERR4 "Seulement 2 bloques peuvent être définit dans un fichier de grammaire."
#define	CODE_ERR5 -5
#define MESS_ERR5 "Une règle est définit mais aucune dérivation lui est spécifié."

void					ft_error(int err_code);
void					ft_debug_deri(void);
void					ft_debug_rule(t_buff rule);
void					ft_debug_term(t_buff term);
void					ft_debug_lltab(void);
int						ft_export_value(char *output_file, t_buff term, t_buff rule);
int						ft_llderi_init(t_buff *rule, t_buff *term);
int						ft_lltab_eps(t_llderi rule, int mid);
int						ft_lltab_first(t_llderi rule, int y, int ind, int mid);
int						ft_lltab_follow(t_llderi rule, int y, int ind, int mid);
int						ft_lltab_init(t_buff term, t_buff rule);
int						ft_parse_gramma(char *gramma_file, t_buff *term, t_buff *nterm);
int						ft_parse_readline(char *line, t_buff *term, t_buff *rule);
int						ft_parse_readrule(char *line, t_buff *rule);
int						ft_parse_readterm(char *line, t_buff *term);

#endif
