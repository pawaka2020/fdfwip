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
//problem with printrows
void	ft_drawline(t_point point1, t_point point2, void *mlx, void *win)
{
	double deltaX;
	double deltaY;
	int pixels;
	double pixelX;
	double pixelY;

	deltaX = point2.x - point1.x;
	deltaY = point2.y - point1.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = point1.x;
	pixelY = point1.y;
	while (pixels)
	{
		//mlx_pixel_put(mlx, win, pixelX, pixelY, 0xFFFFFFFF);
		mlx_pixel_put(mlx, win, pixelX, pixelY, 0x565251);
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

void	printrows(void *mlx, void *win, t_mapdata mapdata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mapdata.meta.size -1)
	{
		ft_drawline(mapdata.points[i], mapdata.points[i + 1], mlx, win);
		printf("PRINTROW:drawing from %d to %d\n", i, i+1);
		i++;
		j++;
		if (j == mapdata.meta.columns - 1)
		{
			i++;
			j = 0;
		}
	}
}

void	printcolumns(void *mlx, void *win, t_mapdata mapdata)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while  (k < mapdata.meta.columns )
	{
		while (j < mapdata.meta.rows - 2)
		{
			ft_drawline(mapdata.points[i], mapdata.points[i + mapdata.meta.columns], mlx, win);
			//printf("DRAWCOLUMN: %d to %d\n", i, i + mapdata.meta.columns);
			i = i + mapdata.meta.columns;
			j++;
		}
		j = 0;
		k++;
		i = k;
	}
}

void    ft_drawpoints(t_mapdata mapdata, void *mlx, void *win)
{
	//mlx_pixel_put(mlx, win, 1440/2, 900/2 - 50, 0xFF0000);
	printrows(mlx, win, mapdata);
	//ft_drawline(mapdata.points[0], mapdata.points[0 + 1], mlx, win);
	printcolumns(mlx, win, mapdata);
	//printdots(mlx, win, mapdata);
	mlx_pixel_put(mlx, win, 720, 400, 0xFF0000);
}
//mlx_pixel_put(mlx, win, 100, 100, 0xFFFFFFFF);
