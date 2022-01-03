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
int	main(int argc, char **argv)
{
	if (ft_valid(argc, argv))
		ft_startfdf(argv[1]);
	else
		printf("ERROR: invalid parameter\n");
}
