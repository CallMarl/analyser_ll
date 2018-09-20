/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/20 16:46:16 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
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

static void			ft_lltab_insertfollow(int *line, int *value, size_t size)
{
	size_t			i;
	size_t			j;
	int				y;

	i = 0;
	y = ft_lltab_getnbrule();
	while (i < size && value[i] != -1)
	{
		j = 0;
		//ft_printf(" %d ", value[i]);
		while (j < g_llterm.cr + 1 && line[j] != value[i] && line[j] != -1)
				j++;
		line[j] = value[i];
		i++;
	}
	//ft_putchar('\n');
}

static int			ft_lltab_isnullvalue(t_intarr *first, int y)
{
	int				i;
	int				*line;

	i = 0;
	line = first->arr[y];
	while (i < first->max_x && line[i] != -1)
	{
		if (line[i] == g_lllast)
			return (1);
		i++;
	}
	return (0);
}

static void			ft_lltab_initfollow_aux(t_intarr *follow, t_intarr *first, int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	ft_printf("ind : %d\n", ind);
	tmp = (t_llderi *)g_llderi.buff;
	if (ind == 0)
		ft_lltab_insertfollow(follow->arr[y - 1], &g_lllast, 1); //On ajoute $ car l'axiom
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
					ft_lltab_initfollow_aux(follow, first, tmp[i].y, tmp[i].y - 1);
					ft_lltab_insertfollow(follow->arr[y - 1], follow->arr[tmp[i].y - 1], follow->max_x);
				}
				else if (ind != tmp[i].y - 1)
				{
					if (tmp[i].deri[j + 1] < g_llpiv)
						ft_lltab_insertfollow(follow->arr[y - 1], first->arr[tmp[tmp[i].deri[j + 1]].y - 1], first->max_x);
					else
						ft_lltab_insertfollow(follow->arr[y - 1], &tmp[i].deri[j + 1], 1);
				}
				else if (ft_lltab_isnullvalue(first, y - 1))
					ft_lltab_insertfollow(follow->arr[y - 1], &g_lllast, 1); //On ajoute ca annulable
			}
			j++;
		}
		i++;
	}
//	ft_putendl("\nFollow arr:");
//	ft_debug_intarr(follow);
}

extern t_intarr		*ft_lltab_firstforfollow(t_intarr *first, int x, int y)
{
	int				i;
	t_intarr		*arr;
	t_llderi		*tmp;

	i = 0;
	arr = ft_alloc_intarr(x, y);
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_lltab_insertfollow(arr->arr[tmp[i].y - 1], first->arr[i], arr->max_x);		
		i++;
	}
	return (arr);
}

extern void			ft_lltab_initfollow(t_intarr *follow, t_intarr *first)
{
	int				i;
	t_llderi		*tmp;
	t_intarr		*ffirst;

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	ffirst = ft_lltab_firstforfollow(first, first->max_x, follow->max_y);
	while (i < ffirst->max_y)
	{
		ft_printf("\nflag%d", i);
		ft_lltab_initfollow_aux(follow, ffirst, i + 1, i);
		i++;
	}
	//unset ffirst
}
// */
