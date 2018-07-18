/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liball.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:33:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 18:15:40 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBALL_H
# define LIBALL_H

# include "libft.h"

typedef struct s_lltab	t_lltab;
typedef struct s_llderi	t_llderi;
typedef struct s_llterm	t_llterm;

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
** nom de la dérivation
** y index de la regle dérivé
** taille du tableau de dérivation
** table des dérivation
*/

struct					s_llderi
{
	char				*rule;
	int					y;
	size_t				d_size;
	int					*deri;
};

struct					s_llterm
{
	int					i;
	char				*term;
};

void					ft_debug_llderi(t_buff llderi);
void					ft_debug_lltab(t_lltab lltab);
void					ft_debug_llterm(t_buff llterm);

void					ft_del_all(t_lltab *lltab, t_buff *llderi, t_buff *llterm);
int						ft_import_all(int fd, t_lltab *lltab, t_buff *llderi, t_buff *llterm);

#endif
