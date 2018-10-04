/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/10/04 16:45:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Pour tout production de Suivant(S):
** On a (alpha) et b (beta) deux élément d'une regle dérivé qui peuvent etre soit
** un terminal soit un non terminal, A un élément non-terminal, c un élément 
** terminal et ε représentation du du caractere null.
**
** De base, placer $ (fin de chaine) dans Suivant(S) puisque S est l'axiome de la
** grammaire.
**
** Si la regle dérivé correspond à une regle de la forme S :: aA Suivant(A) 
** équivaux à Suivant(S).
**
** Si la regle dérivé correspond à une regle de la forme S :: aAb Suivant(A)
** équivaux à Premier(b).
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
** on considéra qu'un élément ε le précede si l'élément non-terminal est placé
** en fin de dérivation on considérera qu'un élément ε le suit.
**
*/

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
extern t_intarr		g_llffirst;
extern t_intarr		g_llfollow;
extern int			g_llpiv;
extern int			g_lllast;

static void			ft_lltab_initfollow(int y, int ind);

static void			ft_lltab_followcase(int y, int ind, t_llderi cur, size_t j)
{
	int				rule;
	int				first;

	rule = -1;
	first = -1;
	if (j + 1 == cur.d_size)
		rule = cur.y;
	if (j + 1 < cur.d_size)
	{
		rule = cur.deri[j + 1];
		if (rule < g_llpiv && ft_utils_isnullvalue(g_llffirst.arr[rule - 1], g_llffirst.max_x))
		{
			first = rule;
			rule = cur.y;
		}
	}
	if (rule < g_llpiv && g_llfollow.arr[rule - 1][0] == -1 && rule != ind)
		ft_lltab_initfollow(rule, ind);
	if (rule >= g_llpiv)
		ft_utils_insert(g_llfollow.arr[y - 1], &rule, 1);
	else
	{
		ft_utils_insert(g_llfollow.arr[y - 1], g_llfollow.arr[rule - 1], g_llfollow.max_x);
		if (ft_utils_isnullvalue(g_llfollow.arr[rule - 1], g_llfollow.max_x))
			ft_utils_insertnull(g_llfollow.arr[y - 1]);
	}
	if (first != -1)
		ft_utils_insert(g_llfollow.arr[y - 1], g_llffirst.arr[first - 1], g_llfollow.max_x);
}

static void			ft_lltab_initfollow(int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	tmp = (t_llderi *)g_llderi.buff;
	if (ind == 0)
		ft_utils_insertnull(g_llfollow.arr[y - 1]);
	i = 0;
	while (i < g_llpiv)
	{
		j = 0;
		while (j < tmp[i].d_size)
		{
			if (tmp[i].deri[j] == y)
				ft_lltab_followcase(y, ind, tmp[i], j);
			j++;
		}
		i++;
	}
}

extern void			ft_lltab_follow()
{
	int				i;
	t_llderi		*tmp;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_lltab_initfollow(tmp[i].y, i);
		i++;
	}
}
// */
