/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:22:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/06/29 18:50:49 by pprikazs         ###   ########.fr       */
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

static int			ft_useracces(int right)
{
	int				ret;

	ret = 0;
	if (right >= 4)
	{
		ret |= S_IRUSR;
		right -= 4;
	}
	if (right >= 2)
	{
		ret |= S_IWUSR;
		right -= 2;
	}
	if (right == 1)
		ret |= S_IXUSR;
	return (ret);
}

static int			ft_otheracces(int right)
{
	int				ret;

	ret = 0;
	if (right >= 4)
	{
		ret |= S_IROTH;
		right -= 4;
	}
	if (right >= 2)
	{
		ret |= S_IWOTH;
		right -= 2;
	}
	if (right == 1)
		ret |= S_IXOTH;
	return (ret);
}

static int			ft_groupacces(int right)
{
	int				ret;

	ret = 0;
	if (right >= 4)
	{
		ret |= S_IRGRP;
		right -= 4;
	}
	if (right >= 2)
	{
		ret |= S_IWGRP;
		right -= 2;
	}
	if (right == 1)
		ret |= S_IXGRP;
	return (ret);
}

static int			ft_openright(char *right)
{
	int				val;
	int				cur;
	int				ret;

	ret = 0;
	if (right == 0)
		return (0);
	if (!ft_strisnumber(right) || ft_strlen(right) > 3)
		return (0);
	val = ft_atoi(right);
	if (val <= 0)
		return (0);
	cur = val % 10;
	val /= 10;
	ft_putnbr(cur);
	ret |= ft_otheracces(cur);
	if (val == 0)
		return (ret);
	cur = val % 10;
	val /= 10;
	ft_putnbr(cur);
	ret |= ft_groupacces(cur);
	if (val == 0)
		return (ret);
	cur = val % 10;
	val /= 10;
	ret |= ft_useracces(cur);
	return (ret);
}

extern int			ft_export_value(char *output_file)
{
	int				fd;

	// Ajouter le gestion des erreur à l'ouverture du fichier
	if ((fd = open(output_file, O_CREAT | O_WRONLY, ft_openright("41")) < -1))
		return (-1);
	ft_putendl(output_file);
	ft_export_lltab(fd);
	(void)output_file;
	return (1);
}
