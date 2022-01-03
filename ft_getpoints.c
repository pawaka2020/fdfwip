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
ft_getstring gets string from map file using read()
then ft_convert converts the string into point array.
ft_getpoints returns the result from ft_convertpoint.
*/
t_points	*ft_getpoints(char *map)
{
	char	*str;
	t_point	*points;

	str = ft_getstring(map);
	points = ft_convert(str);
	return (0);
}
