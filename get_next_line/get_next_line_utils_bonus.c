/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:32:25 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/16 21:32:52 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *txt, int c)
{
	if (!txt)
	{
		return (NULL);
	}
	while (*txt != '\0' && *txt != c)
	{
		txt++;
	}
	if (*txt == c)
	{
		return (txt);
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *txt, char *buff)
{
	int		i;
	int		j;
	int		size;
	char	*result;

	if (!txt)
	{
		txt = malloc(sizeof(char) * 1);
		txt[0] = '\0';
	}
	size = ft_strlen(txt) + ft_strlen(buff);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (txt[++i] != '\0' && i < size)
		result[i] = txt[i];
	j = 0;
	while (buff[j] != '\0' && i < size)
		result [i++] = buff[j++];
	result[i] = '\0';
	free(txt);
	return (result);
}
