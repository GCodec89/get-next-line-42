/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:38:24 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/13 18:44:30 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *txt, int c)
{
	char	ch;

	ch = (char)c;
	if (!txt)
	{
		return (NULL);
	}
	while (*txt != '\0' && *txt != ch)
	{
		txt++;
	}
	if (*txt == ch)
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
