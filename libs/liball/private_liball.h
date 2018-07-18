/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_liball.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:17:14 by pprikazs          #+#    #+#             */
/*   Updated: 2018/07/18 17:17:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_LIBALL_H
# define PRIVATE_LIBALL_H

int			ft_import_lltab(t_buff *content, t_lltab *lltab, int *cr);
int			ft_import_llderi(t_buff *content, t_buff *llderi, int *cr);
int			ft_import_llterm(t_buff *content, t_buff *llterm, int *cr);

int			ft_utils_alloclltab(t_lltab *lltab, int y, int x);

#endif 
