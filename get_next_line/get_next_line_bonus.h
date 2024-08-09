/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:31:22 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/16 21:32:01 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *txt, char *buff);
int		ft_strlen(char *str);
char	*ft_strchr(char *txt, int c);

#endif