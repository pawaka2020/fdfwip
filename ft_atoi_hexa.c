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

int getnb(char c)
{
	int	i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int     ft_atoi_hexa(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while(i++, str[i] && str[i] != ' ')
		res = (res * 16) + getnb(str[i]);
	return (res);
}
/*
int	main(void)
{
	char	*str = "0xFFFFFFFF";
	str = str + 2;
	int	i = ft_atoi_hexa(str);
	printf("i = %d\n", i);
}
*/
