/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:36:59 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/14 18:18:57 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*what_is_left(char *txt)
{
	char	*left;
	int		i;
	int		j;

	i = 0;
	while (txt[i] != '\0' && txt[i] != '\n')
		i++;
	if (!txt[i])
	{
		free(txt);
		return (NULL);
	}
	left = malloc(sizeof(char) * (ft_strlen(txt) - i + 1));
	if (!left)
		return (NULL);
	i++;
	j = 0;
	while (txt[i] != '\0')
		left[j++] = txt[i++];
	left[j] = '\0';
	free(txt);
	return (left);
}

static char	*trim_line(char *txt)
{
	char	*line;
	int		i;

	i = 0;
	if (!txt[i])
		return (NULL);
	while (txt[i] != '\0' && txt[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (txt[i] != '\0' && txt[i] != '\n')
	{
		line[i] = txt[i];
		i++;
	}
	if (txt[i] == '\n')
	{
		line[i] = txt[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_full_line(int fd, char *txt)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
	{
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(txt, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(txt);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		txt = ft_strjoin(txt, buff);
	}
	free(buff);
	return (txt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*txt;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	txt = get_full_line(fd, txt);
	if (!txt)
	{
		return (NULL);
	}
	line = trim_line(txt);
	txt = what_is_left(txt);
	return (line);
}

/*int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	char	*file;

	file = "tests/simple";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file.\n");
		return (1);
	}
	i = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line%d: %s", i, line);
		i++;
		line = get_next_line(fd);
	}
	printf("\n");
	close(fd);
	return (0);
}*/
