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
t_pointmeta getmeta(char *str)
{
	t_pointmeta	meta;

	meta.size = 0;
	meta.rows = 0;
	meta.columns = 0;
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
	meta.size++;
	meta.rows++;
	meta.columns--;
	printf("\nsize = %d\n", meta.size);
	printf("rows = %d\n", meta.rows);
	printf("columns = %d\n", meta.columns);
	return (meta);
}

t_point *ft_convert(char *str)
{
	t_pointmeta meta;
	t_point *points;
	int x;
	int y;
	int z;
	int i;
	
	meta = getmeta(str);
	points = (t_point *)malloc(meta.size * sizeof(t_point));
	x = -5;
	y = 0;
	z = -1;
	i = 0;
	printf("\npoints:\n");
	while (*str)
	{
		
		if(*str >= '0' && *str <= '9')
		{
			x = x + 5;
			points[i].x = x;
			points[i].color = 0;
			points[i].y = y;
			//points[i].z = readfromvalue;
			printf("%d: x = %d, y = %d\n", i, points[i].x, points[i].y);
			i++;
		}
		else if (*str == '\n')
		{
			x = -5;
			y = y + 5;
		}
		str++;
	}
	return (points);
}

char *ft_getstring(char *map)
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

t_point	*ft_getpoints(char *map)
{
	char	*str;
	t_point	*points;

	str = ft_getstring(map);
	points = ft_convert(str);
	return (points);
}

void    ft_drawmap(char *map)
{
	t_point *points;

	points = ft_getpoints(map);
	//draw(points);
}
//gcc ft_drawmap.c *.a
int	main(void)
{
	ft_drawmap("maps/easy.fdf");
}