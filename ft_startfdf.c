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
Starts fdf program on the Gnome virtual machine.
This program can not be run through a SSH remote terminal.
The map parameter is from argv[1], the first and only parameter of fdf (eg: maps/map.fdf)
*/
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
