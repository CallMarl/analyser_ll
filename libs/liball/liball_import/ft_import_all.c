/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 17:30:46 by                   #+#    #+#             */
/*   Updated: 2018/07/23 11:31:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liball.h"
#include "libft.h"
#include "private_liball.h"

/*
** -1 Erreur d'allocation
** -2 Erreur de lecture de fichier
** -3 Fichier trop grand
*/

extern int		ft_import_all(int fd, t_lltab *lltab, t_buff *llderi, t_buff *llterm)
{
	int		ret;
	int		cr;
	t_buff	gmr;

	ret = 0;
	if ((ret = ft_read(fd, &gmr, FT_BUFF_SIZE)) < 0)
		return (ret);
	cr = 0;
	ret = ft_import_lltab(&gmr, lltab, &cr);
	if (ret < 0)
		return (ret);
	ret = ft_import_llderi(&gmr, llderi, &cr);
	if (ret < 0)
		return (ret);
	ret = ft_import_llterm(&gmr, llterm, &cr);
	ft_buffdel(&gmr);
	return (ret);
}
