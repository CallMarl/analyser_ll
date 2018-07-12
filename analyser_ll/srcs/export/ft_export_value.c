/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:22:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 17:45:39 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "analyser_ll.h"
#include "liball.h"
#include "libft.h"

extern int			ft_export_value(char *output_file)
{
	int				fd;

	// Ajouter le gestion des erreur à l'ouverture du fichier
	if (((fd = open(output_file, O_CREAT | O_RDWR, ft_access("755"))) < 0))
		return (-6);
	ft_putendl(output_file);
	ft_export_lltab(fd);
	ft_export_llderi(fd);
	ft_export_llterm(fd);
	close(fd);
	return (1);
}
