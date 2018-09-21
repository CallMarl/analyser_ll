/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/21 03:11:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
extern t_intarr		g_llffirst;
extern t_intarr		g_llfollow;
extern int			g_llpiv;
extern int			g_lllast;

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
** Premier(b) et à Suivant(S).
**
** On remarque ici que l'algorithm est basé que sur les éléments de droite des
** dérivé c'est à dire les dérivation, on chercher à calculer l'ensemble suivant
** des non Terminaux. Si l'élément non terminal est placé en début de dérivation
** on considéra ** qu'un élément ε le précede si l'élément non-terminal est placé
** en fin de dérivation on considérera qu'un élément ε le suit.
**
*/

static void			ft_lltab_initfollow(int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	ft_printf("ind : %d\n", ind);
	tmp = (t_llderi *)g_llderi.buff;
	if (ind == 0)
		ft_utils_insert(g_llfollow.arr[y - 1], &g_lllast, 1); //On ajoute $ car l'axiom
	i = 0;
	while (i < g_llpiv)
	{
		j = 0;
		while (j < tmp[i].d_size)
		{
			if (tmp[i].deri[j] == y)
			{
				if (ind != tmp[i].y - 1 && j + 1 == tmp[i].d_size && tmp[i].deri[j] < g_llpiv) //ind != tmp[i].y (boucle infinie)
				{
					ft_lltab_initfollow(tmp[i].y, tmp[i].y - 1);
					ft_utils_insert(g_llfollow.arr[y - 1], g_llfollow.arr[tmp[i].y - 1], g_llfollow.max_x);
				}
				else if (ind != tmp[i].y - 1)
				{
					if (tmp[i].deri[j + 1] < g_llpiv)
						ft_utils_insert(g_llfollow.arr[y - 1], g_llffirst.arr[tmp[tmp[i].deri[j + 1]].y - 1], g_llffirst.max_x);
					else
						ft_utils_insert(g_llfollow.arr[y - 1], &tmp[i].deri[j + 1], 1);
				}
				else if (ft_utils_isnullvalue(g_llffirst.arr[y - 1]))
					ft_utils_insert(g_llfollow.arr[y - 1], &g_lllast, 1); //On ajoute ca annulable
			}
			j++;
		}
		i++;
	}
}

extern void			ft_lltab_follow()
{
	int				i;

	i = 0;
	while (i < g_llffirst.max_y)
	{
		ft_printf("\nflag%d", i);
		ft_lltab_initfollow(i + 1, i);
		i++;
	}
}
// */
