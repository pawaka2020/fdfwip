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
Closes fdf once Esc key (0xff1b) is pressed
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
