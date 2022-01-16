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

# include "fdf.h"
//squrt is rquired
void	ft_drawline(t_point point1, t_point point2, void *mlx, void *win)
{
/*
	point1 = {0, 0, 0};
	point2 = {0, 5, 0};
*/
	double deltaX;
	double deltaY;
	int pixels;
	double pixelX;
	double pixelY;

	deltaX = point1.x - point2.x;
	deltaY = point1.y - point2.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = point1.x;
	pixelY = point1.y;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, 0xFFFFFFFF);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
}

void	printdots(void *mlx, void *win, t_mapdata mapdata)
{
	int i;

	i = 0;
	while (i < mapdata.meta.size)
	{
		mlx_pixel_put(mlx, win, mapdata.points[i].x, mapdata.points[i].y, 0xFFFFFFFF);
		i++;
	}
}

void    ft_drawpoints(t_mapdata mapdata, void *mlx, void *win)
{
	//mlx_pixel_put(mlx, win, 100, 100, 0xFFFFFFFF);
	//mlx_pixel_put(mlx, win, 200, 500, 0xFFFFFFFF);
	//t_point point1 = {200, 700, 0xFFFFFFFF};
	//t_point point2 = {100, 500,0XFFFFFFFF};
	//ft_drawline(mapdata.points[1], mapdata.points[2], mlx, win);

	printdots(mlx, win, mapdata);
	mlx_pixel_put(mlx, win, 1440/2, 900/2, 0xFF0000);

}
//mlx_pixel_put(mlx, win, 100, 100, 0xFFFFFFFF);
