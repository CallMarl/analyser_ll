/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:45:28 by pprikazs          #+#    #+#             */
/*   Updated: 2018/09/17 13:23:55 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "analyser_ll.h"
#include "libft.h"

extern t_buff		g_llderi;
extern t_lltab		g_lltab;
extern int			g_llpiv;

/*
** Fonction de recherche de l'ensemble des termes premier dans une grammaire:
** L'algo prends en paramettre la regle dont il faut trouver la valeur premier
** sont index (le numero de la regle) et sa position dans la grammaire.
**
** Si le premiere élément de la règle n'équivaux à elle même alors la grammaire
** est éronné.
** Sinon si le premiere éléments de la règle est un non-termninal on va alors
** itéré sur l'ensemble des règles du buffer g_llderi. En itérant on cherche
** a vérivier si le premiere élément de la règle équivaux à l'index d'une des
** règle de la grammaire (on vérifira toutes les règles du même index y).
** Si oui alors on itérera de la même facon (récursive) sur la sous règle trouvé
** jusqu'à tomber sur une dérivé qui à pour première élément un terminal.
**
** On entre alors dans la troisième partie de cette algo qui intègre à g_lltab
** l'élément premier de la règke de dérivation.
**
** Note: tout les élément en dessou de g_llpiv sont des non-terminaux, tout les
** éléments au dessus sont des terminaux.
*/

extern int			ft_lltab_first(t_llderi rule, int y, int ind)
{
	int				i;
	int				ret;
	t_llderi		*llderi;

	ret = 0;
	llderi = (t_llderi *)g_llderi.buff;
	if (rule.deri[0] == y)
		return (-1); //Erreur de définition de la gammaire.
	else if (rule.deri[0] < g_llpiv)
	{
		i = 0;
		while (i < g_llpiv && ret >= 0)
		{
			if (rule.deri[0] == llderi[i].y 
					&& (rule.deri[0] != ind && rule.deri[0] != rule.y))
				ret = ft_lltab_first(llderi[i], y, ind);
			i++;
		}
	}
	else if (rule.deri[0] >= g_llpiv)
	{
		g_lltab.lltab[y - 1][rule.deri[0] - g_llpiv] = ind;
		return (1);
	}
	return (ret);
}
