/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/18 22:35:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern int			g_llpiv;

/*
** Pour tout production de Suivant(S):
** On a (alpha) et b (beta) deux élément d'une regle dérivé qui peuvent etre soit
** un terminal soit un non terminal, A un élément non-terminal, c un élément 
** terminal et ε représentation du du caractere null.
**
** De base, placé $ (fin de chaine) dans Suivant(S) puisque S est l'axiome de la
** grammaire.
**
** Si la regle dérivé correspond à une regle de la forme S :: aAb Suivant(A)
** équivaux à Premier(b).
**
** Si la regle dérivé correspond à une regle de la forme S :: aA Suivant(A) 
** équivaux à Suivant(S).
**
** Si la regle dérivé correspond à une regle de la forme S :: aAb 
** mais que b est annulable alors Suivant(A) équivaux à Suivant(S).
**
** Si la regle dérivé correspond à une regle de la forme S :: aAb et que
** b et de la forme b :: c ou b :: ε alors Suivant(A) équivaux à
** Premier(B) et à Suivant(S).
**
** On remarque ici que l'algorithm est basé que sur les éléments de droite des
** dérivé c'est à dire les dérivation, on chercher à calculer l'ensemble suivant
** des non Terminaux. Si l'élément non terminal est placé en début de dérivation
** on considéra ** qu'un élément ε le précede si l'élément non-terminal est placé
** en fin de dérivation on considérera qu'un élément ε le suit.
**
*/

static void			ft_lltab_insertfollow(int *line, int *value)
{
	int				i;
	int				j;
	int				y;

	i = 0;
	y = ft_lltab_getnbrule();
	while (i < y && value[i] != -1)
	{
		while (j < y && line[j] != value[i] && line[j] != -1)
				j++;
		line[j] = value[i];
		i++;
	}
}

static void			ft_lltab_initfollow_aux(int **follow, int **first, int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		j = 0;
		while (j < tmp[i].d_size)
		{
			if (tmp[i].deri[j] == y)
			{
				if (j + 1 == tmp[i].d_size && tmp[i].deri[j + 1] < g_llpiv)
					ft_lltab_initfollow_aux(follow, first, tmp[i].y, ind);
				else
					ft_lltab_insertfollow(follow[ind], first[j]);
			}
			j++;
		}
		i++;
	}
	ft_lltab_insertfollow(follow[ind], follow[y]);
} 

extern void			ft_lltab_initfollow(int **follow, int **first)
{
	int				i;

	i = 0;
	while (i < g_llpiv)
	{
		ft_lltab_initfollow_aux(follow, first, i, i);
		i++;
	}
}
