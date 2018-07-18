/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 18:13:16 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 18:17:04 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"
#include "private_liball.h"

extern void			ft_del_all(t_lltab *lltab, t_buff *llderi, t_buff *llterm)
{
	ft_del_lltab(lltab);
	ft_del_llderi(llderi);
	ft_del_llterm(llterm);
}
