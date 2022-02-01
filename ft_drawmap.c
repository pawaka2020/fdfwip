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
*/
t_pointmeta	getmeta(char *str)
{
	t_pointmeta	meta;

	meta.size = 0;
	meta.rows = 0;
	meta.columns = 0;
	meta.length = 0;
	int i = -1;
	while (i++, str[i])
	{
		if (str[i] == ' ' || str[i] == '\n')
		{
			meta.size++;
			if (str[i] == '\n')
			{
				meta.rows++;
				if (meta.rows == 1)
					meta.columns = meta.size + 1;
			}
		}
	}
	meta.rows++;
	meta.columns--;
	//meta.size = meta.rows * meta.columns;
	printf("\nsize = %d\nrows = %d\ncolumns = %d\n", meta.size, meta.rows, meta.columns);
	meta.length = 0;
	return (meta);
}
//rows = number of newlines + 1.
int	getrows(char *str)
{
	int	i;
	int 	rows;

	i = -1;
	rows = 0;
	while (i++, str[i])
		if(str[i] == '\n' || str[i] == 0)
			rows++;
	printf("rows = %d\n", rows);
	return (rows);
}
//columns = number of non ' ' strings before the first newline.
int	getcolumns(char *str)
{
	int	i;
	int	columns;

	i = 0;
	columns = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			if (i == 0)
				columns++;
			else if (i != 0 && str[i-1] == ' ')
				columns++;
		}
		i++;
	}
	printf("columns = %d\n", columns);
	return (columns);
}

t_pointmeta	getmeta2(char *str)
{
	t_pointmeta	meta;
	meta.rows = getrows(str);
	meta.columns = getcolumns(str);
	meta.size = meta.rows * meta.columns; 
	meta.length = 0;
	printf("size = %d\n", meta.size);
	return (meta);
}
//resolution is 1440 x 900
void	centralize(int *x, int *y, t_pointmeta meta, int len)
{
	int	centerprogramX;
	int	centerprogramY;
	double	centershapeX;
	double	centershapeY;
	int	deltaX;
	int	deltaY;

	centerprogramX = 1440/2;
	centerprogramY = 900/2;
	//len adjustments here, default 100
	centershapeX = ((meta.columns - 1)/2.0) * len;
	centershapeY = ((meta.rows - 1)/2.0) * len;
	//printf("centerprogramX = %d, centerprogramY = %d\n", centerprogramX, centerprogramY);
	//printf("centershapeX = %f, centershapeY = %f\n", centershapeX, centershapeY);
	//printf("deltaX = %d, deltaY = %d\n", deltaX, deltaY);
	*x = *x + (centerprogramX - centershapeX);
	*y = *y + (centerprogramY - centershapeY);
}

int	ft_getnbrlen(int i)
{
	int	len;

	len = 0;

	if (i < 0)
	{
		i = i * -1;
		len++;
	}
	else if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

void	ft_setpoint(char **str, t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(*str);
	if (point->z <= 0)
		point->color = 0xFFFFFF;
	else
		point->color = (0xFFFFFF) - (838848 * point->z);
	*str = *str + ft_getnbrlen(point->z);
}

void	ft_setcolor(char **str, t_point *point)
{
	*str = *str + 3;
	point->color = ft_atoi_hexa(*str);
	*str = *str + 7;
}
//resolution ; 1440 x 900
int	adjustlength(t_pointmeta meta)
{
	int	length;
	int	columns = meta.columns;
	int	rows = meta.rows;

	int size1 = (1440 * 0.75)/columns;
	int size2 = (900 * 0.75)/rows;
	if (size1 > size2)
		length = size2;
	else
		length = size1;
	return (length);
}

t_mapdata	ft_convert(char *str)
{
	t_mapdata	mapdata;
	int	x;
	int	y;
	int	z;
	int	i;
	int	originX;
	int	originY;
	int	len;

	mapdata.meta = getmeta2(str);
	mapdata.points = (t_point *)malloc(mapdata.meta.size * sizeof(t_point));
	len = adjustlength(mapdata.meta);
	//len = 100;
	originX = 0 - len;
	originY = 0;
	centralize(&originX, &originY, mapdata.meta, len);
	x = originX;
	y = originY;
	mapdata.meta.length = len;
	i = 0;
	while (*str)
	{
		if(*str == '-' || (*str >= '0' && *str <= '9'))
		{
			x = x + len;
			ft_setpoint(&str, &mapdata.points[i], x,  y);
			//printf("%d: x = %d, y = %d, z = %d, color = %d\n", i, mapdata.points[i].x, mapdata.points[i].y, mapdata.points[i].z, mapdata.points[i].color);
			i++;
		}
		else if (*str == ',')
			ft_setcolor(&str, &mapdata.points[i - 1]);
		else if (*str == '\n')
		{
			x = originX;
			y = y + len;
			str++;
		}
		else if (*str == ' ')
			str++;
	}
	//mapdata = ft_transform(mapdata, 0.7854, 0.52);
	mapdata = ft_transform(mapdata, -0.7854, 0.7500);
	//mapdata = ft_transform(mapdata, 0.7854, 0.0);
	//mapdata = ft_transform(mapdata, 0.25, 0.7500);
	//mapdata = ft_transform(mapdata, 0.0, 0.0);
	//mapdata = ft_transform(mapdata, 0.7854, 0.7500);
	i = 0;
	while (i < mapdata.meta.size)
	{
		printf("%d: x = %d, y = %d, z = %d, color = %d\n", i, mapdata.points[i].x, mapdata.points[i].y, mapdata.points[i].z, mapdata.points[i].color);
		i++;
	}

	return (mapdata);
}

char	*ft_getstring(char *map)
{
	int fd;
	char *str;
	char *str2;
	int read;

	fd = open(map, O_RDONLY);
	str = 0;
	read = 0;
	str2 = 0;
	while (read == 0)
	{
		str2 = get_next_line(fd);
		if (str2 == 0)
			read = 1;
		else
			str = ft_strjoin(str, str2);
	}
	free(str2);
	printf("read result:\n%s\n", str);
	return (str);
}

t_mapdata	ft_getpoints(char *map)
{
	char	*str;
	t_mapdata mapdata;

	str = ft_getstring(map);
	mapdata = ft_convert(str);
	return (mapdata);
}
//t_point	*ft_drawmap(char *map)
t_mapdata	ft_drawmap(char *map)
{
	t_mapdata mapdata;
	mapdata = ft_getpoints(map);
	return (mapdata);
}
//gcc ft_drawmap.c *.a
/*
int	main(void)
{
	ft_drawmap("maps/easy.fdf");
}
*/
