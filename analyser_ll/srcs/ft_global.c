/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:02:09 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 17:21:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "liball.h"

/*
** Ensemble des varibles globales, ceci correspond également au données qui
** seront exporté dans le fichier binaire.
*/

/*
** Table d'analyse LL.
*/

t_lltab		g_lltab = {
	0, 0, 0
};

/*
** Buffeur pour la list des dérivations il contient en paramettre un 
** structure t_llderi.
*/

t_buff		g_llderi = {
	0, 0, 0, 0
};

t_buff		g_llterm = {
	0, 0, 0, 0
};

/*
** Afin de différencier les terminaux des non-terminaux, un pivot est
** définit toutes les valeurs dans g_lltab et dans g_llderi en dessous
** du pivot correspondent à des terminaux, toutes les valeur au dessus
** correspond au non-terminaux
**
** g_llpiv correspond également au nombre délément dans g_llderi 
** (g_llderi.cr).
**
** la différentce entre un terminal et g_llpiv concorde également 
** avec l'axe des x dans g_lltab. Puisque les terminaux sont l'ensemble 
** des valeur au dessus du pivot.
*/

int			g_llpiv = -1;
