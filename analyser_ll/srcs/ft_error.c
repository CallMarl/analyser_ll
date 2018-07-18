/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:58:52 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 12:00:08 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "analyser_ll.h"

static char		**ft_error_initmessage(void)
{
	static char	*err_mess[7] = {
		0, MESS_ERR1, MESS_ERR2, MESS_ERR3, MESS_ERR4, MESS_ERR5, MESS_ERR6
	};

	return (err_mess);
}

extern void			ft_error(int err_code)
{
	char		**err_mess;

	err_mess = ft_error_initmessage();
	ft_putendl(err_mess[-err_code]);
	if (err_code == CODE_ERR2)
		ft_putendl("\tUsage : ./analyser_ll source.gmr dest.all");
}
