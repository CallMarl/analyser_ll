/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:30:46 by                   #+#    #+#             */
/*   Updated: 2018/07/17 17:48:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"

extern int		ft_import(int fd, t_lltab *lltab, t_buff *llderi, t_buff *llterm)
{
	int		ret;

	ret = 0;
	ret = ft_import_lltab(fd, lltab);
	if (ret < 0)
		return (ret);
	ret = ft_import_llderi(fd, llderi);
	if (ret < 0)
		return (ret);
	ret = ft_import_llterm(fd, llterm);
	return (ret);
}
