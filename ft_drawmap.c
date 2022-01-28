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
	printf("\nsize = %d\nrows = %d\ncolumns = %d\n", meta.size, meta.rows, meta.columns);
	return (meta);
}
//resolution is 1440 x 900
void	centralize(int *x, int *y, t_pointmeta meta)
{
	int	centerprogramX;
	int	centerprogramY;
	double	centershapeX;
	double	centershapeY;
	int	deltaX;
	int	deltaY;

	centerprogramX = 1440/2;
	centerprogramY = 900/2;
	centershapeX = ((meta.columns - 1)/2.0) * 100;
	centershapeY = ((meta.rows - 1)/2.0) * 100;
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
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}


int	ft_setz(char **str)
{
	int	i;
	int	nbrlen;

	i = ft_atoi(*str);
	nbrlen = ft_getnbrlen(i);
	*str = *str + nbrlen;
	return(i);
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

	mapdata.meta = getmeta(str);
	mapdata.points = (t_point *)malloc(mapdata.meta.size * sizeof(t_point));
	originX = -100;
	originY = 0;
	centralize(&originX, &originY, mapdata.meta);
	//adjustlength(&len);
	len = 100;
	x = originX;
	y = originY;
	//z = 0;
	i = 0;
	printf("\npoints:\n");
	while (*str)
	{
	/*
		z = 1;
		if (*str == '-')
		{
			z = -1;
		}
	*/
		if(*str == '-' || (*str >= '0' && *str <= '9'))
		{
			x = x + len;
			mapdata.points[i].x = x;
			mapdata.points[i].y = y;
			mapdata.points[i].z = ft_setz(&str);
			//mapdata.points[i].z = 0;
			//ft_setcolor(&mapdata.points[i].color, &mapdata.points[i].colorset);
			mapdata.points[i].color = 0;
			mapdata.points[i].colorset = 0;
			printf("%d: x = %d, y = %d, z = %d\n", i, mapdata.points[i].x, mapdata.points[i].y, mapdata.points[i].z);
			i++;

		}
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
	mapdata = ft_transform(mapdata, 0.7854, 0.7500);
	//mapdata = ft_transform(mapdata, 1.5708, 0.52);
	//mapdata = ft_transform(mapdata, 0.6999, 0.52);
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
