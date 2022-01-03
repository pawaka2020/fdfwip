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
Makes sure the parameter is a valid map file.
Only 1 parameter is allowed, though it is uncertain whether or not 
it is needed to also validate the type of parameter.
For now, return 1 if there is only one parameter entered.
*/
int	ft_valid(int argc, char **argv)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}
//testing only
/*
int	main(void)
{

}
*/
