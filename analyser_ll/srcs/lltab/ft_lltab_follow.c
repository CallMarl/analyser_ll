/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltab_follow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:50:42 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/25 18:26:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern t_buff		g_llderi;
extern t_buff		g_lltab;

extern int			ft_lltab_follow(t_rule rule, int y , int ind, int mid)
{
	int				i;
	int				j;
	int				tmp;

	i = 0;
	while (i < mid)
	{
		j = 0;
		while (j < g_llderi[i].d_size)
		{
			if (g_llderi[i].deri[j] == rule.y && j < d_size - 1)
			{
				tmp = g_llderi[i].deri[j + 1];
				if (tmp >= mid)
					// Ajout du terminal dans l'ensemble suivant
				else if (tmp <= mid)
					// Ajout des de l'ensemble premier à suivant
			}
			else if (g_llderi[i].deri[j] == rule.y && j == d_size - 1)
				//Ajout de $ dans suivant
			j++;
		}
	}
}
