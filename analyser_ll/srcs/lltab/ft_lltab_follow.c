/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/19 19:13:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_buff		g_llterm;
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
** Premier(b) et à Suivant(S).
**
** On remarque ici que l'algorithm est basé que sur les éléments de droite des
** dérivé c'est à dire les dérivation, on chercher à calculer l'ensemble suivant
** des non Terminaux. Si l'élément non terminal est placé en début de dérivation
** on considéra ** qu'un élément ε le précede si l'élément non-terminal est placé
** en fin de dérivation on considérera qu'un élément ε le suit.
**
*/
/*
static void			ft_lltab_insertfollow(int *line, int *value)
{
	size_t			i;
	size_t			j;
	int				y;

	i = 0;
	y = ft_lltab_getnbrule();
	while (i < g_llterm.cr + 1 && value[i] != -1)
	{
		j = 0;
		while (j < g_llterm.cr && line[j] != value[i] && line[j] != -1)
		{
				j++;
		}
		line[j] = value[i];
		i++;
	}
}

static void			ft_lltab_initfollow_aux(int **follow, int **first, int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	ft_putstr("\ny : ");
	ft_putnbr(y);
	ft_putstr("\nind : ");
	ft_putnbr(ind);
	ft_putchar('\n');

	i = 0;
	tmp = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		ft_putstr("\ni : ");
		ft_putnbr(i);
		ft_putstr("\nd_size : ");
		ft_putnbr(tmp[i].d_size);
		ft_putchar('\n');
		j = 0;
		while (j < tmp[i].d_size)
		{
			if (tmp[i].deri[j] == y + 1)
			{
				ft_putendl("dedans");
				if (j + 1 == tmp[i].d_size && tmp[i].deri[j] < g_llpiv)
				{
					ft_putendl("la1");
					ft_lltab_initfollow_aux(follow, first, tmp[i].y - 1, ind);
				}
				else if (tmp[i].deri[j + 1] < g_llpiv)
				{
					ft_putendl("la2");
					ft_lltab_insertfollow(follow[tmp[ind].y - 1], first[tmp[i].deri[j + 1] - 1]);
					ft_putendl("Follow arr:");
					ft_debug_intarr(follow, g_llterm.cr + 1, 2);
				}
				else if (tmp[i].deri[j + 1] >= g_llpiv)
				{
					ft_putendl("la3");
					ft_lltab_insertfollow(follow[tmp[i].y - 1], &tmp[i].deri[j + 1]);
					ft_putendl("Follow arr:");
					ft_debug_intarr(follow, g_llterm.cr + 1, 2);
				}
			}
			j++;
		}
		i++;
	}
	ft_lltab_insertfollow(follow[tmp[ind].y - 1], follow[y]);
} 

extern void			ft_lltab_initfollow(int **follow, int **first, int y)
{
	int				i;

	i = 0;
	while (i < y)
	{
		ft_lltab_initfollow_aux(follow, first, i, i);
		i++;
	}
}
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
		while (j < g_llterm.cr + 1 && line[j] != value[i] && line[j] != -1)
		{
				j++;
		}
		line[j] = value[i];
		i++;
	}
}

static void			ft_lltab_initfollow_aux(int **follow, int **first, int y, int ind)
{
	int				i;
	size_t			j;
	t_llderi		*tmp;

	if (ind == 0)
		ft_lltab_insertfollow(follow[tmp[ind].y - 1], &(g_llpiv + g_llterm.cr), 1); //On ajoute $ car l'axiom

	ft_putendl("Follow arr:");
	ft_debug_intarr(follow, g_llterm.cr + 1, 2);
}

extern void			ft_lltab_initfollow(int **follow, int **first, int y)
{
	int				i;

	i = 0;
	while (i < g_llpiv)
	{
		ft_lltab_initfollow_aux(follow, first, tmp[i].y, i);
		i++;
	}
}

