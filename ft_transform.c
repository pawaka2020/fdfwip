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


void	getcenter(t_mapdata mapdata, int *centerX, int *centerY)
{
	*centerX = mapdata.points[0].x + (mapdata.points[mapdata.meta.size - 1].x - mapdata.points[0].x)/2;
	*centerY = mapdata.points[0].y + (mapdata.points[mapdata.meta.size - 1].y - mapdata.points[0].y)/2;
}

double	getradians(float deltaX, float deltaY)
{
	double oldrad;
	//start from 0 and specify all use cases going clockwise
	if (deltaY == 0 && deltaX >= 0)
		oldrad = 0;
	else if (deltaY > 0 && deltaX > 0)
		oldrad = atan(deltaY/deltaX);
	else if (deltaY > 0 && deltaX == 0)
		oldrad = 1.5708;
	else if (deltaY > 0 && deltaX < 0)
		oldrad = 3.1415 + atan(deltaY/deltaX);
	else if (deltaY == 0 && deltaX < 0)
		oldrad = 3.1415;
	else if (deltaY < 0 && deltaX < 0)
		oldrad = 3.1415 + atan(deltaY/deltaX);
	else if (deltaY < 0 && deltaX == 0)
		oldrad = 4.7124;
	else if (deltaY < 0 && deltaX > 0)
		oldrad = 6.2832 + atan(deltaY/deltaX);
	//printf("oldrad = %f\n", oldrad * 57.30);
	return (oldrad);
}

t_mapdata       ft_transform(t_mapdata mapdata, float rad1, float rad2)
{
	t_mapdata	mapdata2;
	int	centerX;
	int	centerY;
	float	deltaX;
	float	deltaY;
	double	oldrad;
	double	newrad;
	float	tangent;

	mapdata2 = mapdata;
	//centerX = 720;
	//centerY = 400;
	getcenter(mapdata2, &centerX, &centerY);
	//printf("\ncenterX = %d, centerY = %d\n", centerX, centerY);
	int i = 0;
	while (i < mapdata2.meta.size)
	//while (i < 3)
	{
		int x = mapdata2.points[i].x;
		int y = mapdata2.points[i].y;
		//printf("!!!!before transformation x = %d, y = %d, i = %d\n", x, y, i);
		//printf("centerX = %d, centerY = %d\n", centerX, centerY);
		deltaX = x - centerX;
		deltaY = y - centerY;
		deltaY = deltaY * -1;
		//printf("deltaX = %f, deltaY = %f\n", deltaX, deltaY);
		//printf("a = %f, b = %f\n", a, b);
		tangent = sqrt((deltaX * deltaX) + (deltaY * deltaY));
		//printf("deltaX = %f, deltaY = %f\n", deltaX, deltaY);
		oldrad = getradians(deltaX, deltaY);
		//printf("tangent = %f\n", tangent);
		newrad = oldrad + rad1;
		//printf("after addition, newrad = %f\n", newrad);
		deltaX = tangent * cos(newrad);
		//Y coordinate in a pixel screen is inverse, so we must inverse the result.
		deltaY = tangent * sin(newrad);
		//printf("after transformation, deltaX = %f, deltaY = %f\n", deltaX, deltaY);
		x = deltaX + centerX;
		//x = centerX - deltaX;
		//nothing
		//x = deltaX - centerX;
		//y = deltaY + centerY;
		y = centerY - deltaY;
		//y = deltaY - centerY;
		mapdata2.points[i].x = x;
		mapdata2.points[i].y = y;
		//upward flipping
		mapdata2.points[i].y = centerY - (deltaY * cos(rad2));
		//with z
		//mapdata2.points[i].y = mapdata2.points[i].y + (mapdata2.points[i].z * sin(rad2) * 10 * -1);
		mapdata2.points[i].y = mapdata2.points[i].y + (mapdata2.points[i].z * sin(rad2) * mapdata2.meta.length/8 * -1);
		//printf("after transformation, x = %d, y = %d, i = %d\n", mapdata2.points[i].x, mapdata2.points[i].y, i);
		i++;
	}
	///mapdata2.points[0].color = 9000;
	///printf("after transform, color = %d\n", mapdata2.points[0].color);
	return (mapdata2);
}
