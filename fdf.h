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
//for testing purposes only
# include <stdio.h>
//for exit(0) allowing termination of program
# include <stdlib.h>
/*for write()*/
# include <unistd.h>
/*for O_RDLY to be used together with write()*/
# include <fcntl.h>
/*for malloc() and free()*/
# include <stdlib.h>
# include <math.h>
/*for reading from .fdf file*/
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
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
Points are created by ft_getpoint
*/
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;
/*points metadata, for creating point array*/
typedef struct s_pointmeta
{
	int size;
	int rows;
	int columns;
	int length;
}	t_pointmeta;

typedef	struct	s_mapdata
{
	t_point	*points;
	t_pointmeta meta;
}	t_mapdata;

//fdf functions
/*
Makes sure the parameter is a valid map file.
Only 1 parameter is allowed, though it is uncertain whether or not 
it is needed to also validate the type of parameter.
For now, return 1 if there is only one parameter entered.
*/
int	ft_valid(int argc, char **argv);
/*
Starts fdf program on the Gnome virtual machine.
This program can not be run through a SSH remote terminal.
The map parameter is from argv[1], the first and only parameter of fdf (eg: map.fdf)
*/
int	ft_startfdf(char *map);
/*
Closes fdf once Esc key (0xff1b) is pressed
*/
int	ft_closefdf(int keycode, t_vars *vars);
/*
Draws the map using map file passed by ft_startffd
*/

//t_point	*ft_drawmap(char *map);
t_mapdata ft_drawmap(char *map);
/*
ft_getstring gets string from map file using read()
then ft_convert converts the string into point array.
ft_getpoints returns the result from ft_convertpoint.
*/
//t_point	*ft_getpoints(char *map);
t_mapdata	ft_getpoints(char *map);
/*
Uses read() to convert map in .fdf file into string.
Returns the string afterward.
*/
char	*ft_getstring(char *map);
/*converts map content from ft_getstring into a point array*/
//t_point *ft_convert(char *str);
//t_mapdata	ft_convert(char *str);

t_mapdata	ft_transform(t_mapdata mapdata, float rad1, float rad2);

void	ft_drawpoints(t_mapdata	mapdata, void *mlx, void *win);

int	ft_atoi_hexa(char *str);

#endif
