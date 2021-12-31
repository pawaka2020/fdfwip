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

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
/*
blah blah blah comment
*/
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;
/*
Points on the map output to be connected with lines
Each point has X-coordinate, Y-coordinate and color
Points are created by ft_getpoints function
*/
typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point

#endif
