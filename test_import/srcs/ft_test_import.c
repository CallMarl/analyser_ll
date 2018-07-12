/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_import.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:47:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/12 17:43:18 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "liball.h"
#include "libft.h"

extern t_lltab		g_lltab;
extern t_buff		g_llderi;
extern t_buff		g_llterm;

extern int			ft_test_import(int argc, char *argv[])
{
	int				fd;

	if (argc == 2)
	{
		if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
			return (-1); //Erreur d'ouverture du fichier
		ft_import_lltab(fd, &g_lltab);
		{
			ft_debug_lltab(g_lltab);
		}
		ft_import_llderi(fd, &g_llderi);
		{
			ft_putstr("cr : ");
			ft_putnbr(g_llderi.cr);
			ft_putstr(" e_size : ");
			ft_putnbr(g_llderi.e_size);
			ft_putstr(" b_size : ");
			ft_putnbr(g_llderi.b_size);
			ft_putendl("");
			ft_debug_llderi(g_llderi);
		}
		ft_import_llterm(fd, &g_llterm);
		{
			ft_putstr("cr : ");
			ft_putnbr(g_llderi.cr);
			ft_putstr(" e_size : ");
			ft_putnbr(g_llderi.e_size);
			ft_putstr(" b_size : ");
			ft_putnbr(g_llderi.b_size);
			ft_putendl("");
			ft_debug_llterm(g_llterm);
		}
	}
	(void)argc;
	(void)argv;
	return (0);
}
