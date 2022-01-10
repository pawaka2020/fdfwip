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
ft_valid checks for validity of map file used as program parameter
Then ft_startfdf starts the program using argv[1] to access map file
*/

/*
Starts fdf program on the Gnome virtual machine.
This program can not be run through a SSH remote terminal.
The map parameter is from argv[1], the first and only parameter of fdf (eg: maps/map.fdf)
*/
int     ft_closefdf(int keycode, t_vars *vars)
{
        if (keycode == 0xff1b)
	{
                mlx_destroy_window(vars->mlx, vars->win);
		printf("Esc pressed. Exiting program ...\n");
		exit (0);
	}
}

void    ft_drawmap(char *map)
{
	t_point *points;

	points = ft_getpoints(map);
	// ft_drawpoints(points);
	// ft_joinrows(points);
	// ft_joincolumns(points);
}

int     ft_startfdf(char *map)
{
        printf("map loaded: %s\n", map);

        t_vars  vars;

        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, 1440, 900, "fdf");
				ft_drawmap(map);
        mlx_hook(vars.win, 2, 1L<<0, ft_closefdf, &vars);
        mlx_loop(vars.mlx);
}

int	ft_valid(int argc, char **argv)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if (ft_valid(argc, argv))
		ft_startfdf(argv[1]);
	else
		printf("ERROR: invalid parameter\n");
}
