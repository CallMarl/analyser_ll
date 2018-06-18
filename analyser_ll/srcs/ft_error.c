/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:58:52 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/18 16:32:35 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "analyser_ll.h"

static char		**ft_error_initmessage(void)
{
	static char	*err_mess[6] = {
		0, MESS_ERR1, MESS_ERR2, MESS_ERR3, MESS_ERR4, MESS_ERR5
	};

	return (err_mess);
}

void			ft_error(int err_code)
{
	char		**err_mess;

	err_mess = ft_error_initmessage();
	ft_putendl(err_mess[-err_code]);
	if (err_code == CODE_ERR2)
		ft_putendl("\tUsage : ./analyser_ll source.gmr dest.all");
}
