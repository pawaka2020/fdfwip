/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
This time, instead of a static string, a static array of strings is used.
The string array holds line for every fd introduced to get_next_line
However, due to my coding limitation I let the string array be of a fixed
max size rather than dynamic size depending on the number of different fds
introduced.
It's not elegant but it gets the job done.
*/
#include "get_next_line_bonus.h"

char	*ft_getrawline(int fd, char *str, int size)
{
	char	*buff;
	int		readres;

	buff = malloc(size + 1);
	if (!buff)
		return (0);
	readres = 1;
	while (ft_nlpresent(str) == 0 && readres != 0)
	{
		readres = read(fd, buff, size);
		if (readres == -1)
		{
			free(buff);
			return (0);
		}
		buff[readres] = '\0';
		str = ft_append(str, buff);
	}
	free (buff);
	return (str);
}

//In case of empty feed, the previous function
//returns a string of 1 size, but element \0
char	*ft_prenl(char *rawline)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (rawline[i] == '\0')
		return (0);
	while (rawline[i] && rawline[i] != '\n')
		i++;
	if (rawline[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (0);
	j = -1;
	while (j++, j != i)
		line[j] = rawline[j];
	line[j] = '\0';
	return (line);
}

char	*ft_postnl(char *rawline)
{
	char	*line;
	int		i;
	int		j;

	if (!rawline)
		return (0);
	i = 0;
	while (rawline[i] && rawline[i] != '\n')
		i++;
	if (!rawline[i])
	{
		free(rawline);
		return (0);
	}
	line = malloc((ft_strlen(rawline) - i) + 1);
	if (!line)
		return (0);
	i++;
	j = 0;
	while (rawline[i])
		line[j++] = rawline[i++];
	line[j] = '\0';
	free (rawline);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rawline[2147483647];
	int			size;

	size = BUFFER_SIZE;
	if (fd < 0 || size <= 0)
		return (0);
	rawline[fd] = ft_getrawline(fd, rawline[fd], size);
	if (!rawline[fd])
		return (0);
	line = ft_prenl(rawline[fd]);
	rawline[fd] = ft_postnl(rawline[fd]);
	return (line);
}

// int	main()
// {
// 	int fd1 = open("text", O_RDONLY);
// 	int fd2 = open("text2", O_RDONLY);
// 	printf("Hello\n");
// 	// char *str = "123\n456";
// 	// printf("result = %s\n", before_nl(str));
// }
