/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_import.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:47:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/10 17:09:19 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "liball.h"
#include "libft.h"

extern t_lltab		g_lltab;

extern int			ft_test_import(int argc, char *argv[])
{
	int				fd;

	if (argc == 2)
	{
		if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
			return (-1); //Erreur d'ouverture du fichier
		ft_import_lltab(fd, &g_lltab);
		ft_debug_lltab(g_lltab);
	}
	(void)argc;
	(void)argv;
	return (0);
}
