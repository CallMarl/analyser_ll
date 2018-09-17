/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <pprikazs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/17 14:06:52 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

static void			ft_lltab_follow_first(int follow, int first)
{
	int				x;

	x = 0;
	while (x < g_lltab.max_x)
	{
		if (g_lltab.lltab[first][x] != -1)
			g_lltab.lltab[follow][x] = g_lltab.lltab[first][x];
		x++;
	}
}

/*
** Calcule de l'ensemble suivant pour une regle de dérivation donné:
**
** Pour toutes les règles de dérivation, j'itère sur l'ensemble des terminaux
** et non-terminaux de ces règles, si lorsque j'itère je tombe sur la règle de
** dérivation chercher alors si l'ément juste apres est un non terminal je
** l'ajoute au tableau d'analyse. Sinon si l'élément suivant est un
** non terminal j'ajoute l'esemble des premier du non terminal trouvé à la table
** d'analyse.
**
** Sinon si aucune règle de dérivation ne suis la règle trouvé alors j'ajoute
** $ à la table d'analyse
*/

extern int			ft_lltab_follow(t_llderi rule, int y, int ind)
{
	int				i;
	size_t			j;
	int				tmp;
	t_llderi		*llderi;

	i = 0;
	llderi = (t_llderi *)g_llderi.buff;
	while (i < g_llpiv)
	{
		j = 0;
		while (j < llderi[i].d_size)
		{
			if (llderi[i].deri[j] == rule.y && j < llderi[i].d_size - 1)
			{
				tmp = llderi[i].deri[j + 1];
				if (tmp >= g_llpiv)
					g_lltab.lltab[y - 1][tmp - g_llpiv] = ind;
				else if (tmp < g_llpiv && tmp != rule.y)
					ft_lltab_follow_first(rule.y ,tmp);
				tmp = llderi[i].deri[j + 1];
			}
			else if (llderi[i].deri[j] == rule.y)
				{;} // Ajouter $ à suivant
			j++;
		}
		i++;
	}
	return (1);
}
