/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
Draws the map using map file passed by ft_startffdf
get array of t_point from map using ft_getpoints (refer to fdf.h for t_point)
draw points first with ft_drawpoints, then connect rows and colums
with ft_joinrows and ft_joincolumns respectively.
*/1
void    ft_drawmap(char *map)
{
	t_point *points;

	points = ft_getpoints(map);
	ft_drawpoints(points);
	ft_joinrows(points);
	ft_joincolumns(points);
}
