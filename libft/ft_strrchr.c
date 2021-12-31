/*
like strchr.c but finds the last occurence of c instead
*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = 0;
	while (*s)
	{
		if (*s == (char)c)
			s2 = (char *)s;
		s++;
	}
	if (*s == (char)c)
		s2 = (char *)s;
	return (s2);
}
