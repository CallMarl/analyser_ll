/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:22:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 14:38:09 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "analyser_ll.h"
#include "liball.h"
#include "libft.h"

static int			ft_export_lltab(int fd)
{
	(void)fd;
	return (0);
}

extern int			ft_export_value(char *output_file)
{
	int				fd;

	// Ajouter le gestion des erreur à l'ouverture du fichier
	if ((fd = open(output_file, O_CREAT, ft_access("755")) < -1))
		return (-1);
	ft_putendl(output_file);
	ft_export_lltab(fd);
	(void)output_file;
	return (1);
}
