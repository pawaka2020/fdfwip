#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
void test(int i)
{
	printf("original character = %c\n", i);
	int j = toupper(i);
	printf("toupper result = %c\n", j);
	int k = ft_toupper(i);
	printf("ft_toupper result = %c\n\n", k);
}
int	main(void)
{
	int i = 32;
	while (i < 127)
		test(i++);
}
*/