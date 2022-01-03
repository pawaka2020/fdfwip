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
	int	color;
}	t_point;
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
void	ft_drawmap(char *map);

#endif
