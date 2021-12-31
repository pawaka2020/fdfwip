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

int	ft_closefdf(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
}
/*
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1440, 900, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
*/
int	ft_startfdf(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1440, 900, "fdf2");
	mlx_hook(vars.win, 2, 1L<<0, ft_closefdf, &vars);
	mlx_loop(vars.mlx);
}
/*
Makes sure the parameter is a valid map file. Returns 1 for valid.
*/
int	valid(int argc)
{
	if (argc == 2)
		return (1);
	else
		return(0);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	if (valid(argc);
		ft_startfdf();
	else
		printf("ERROR: invalid parameter\n");
}
