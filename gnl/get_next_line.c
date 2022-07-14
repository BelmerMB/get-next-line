/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/14 16:35:13 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_next(int fd, char **s_buffer, char *buffer);
int			ft_strend(char *buffer);

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*s_buff;

	if(fd > 1023 || fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff = ft_next(fd, &s_buff, buff);
	return (buff);
}

static char	*ft_next(int fd, char **s_buffer, char *buffer)
{
	int	sz_read;
	int	i;

	i = 0;
	sz_read = 0;
	if (!*s_buffer)
	{
		sz_read = read(fd, buffer, BUFFER_SIZE);
		if (sz_read < 0)
			return (NULL);
		buffer[sz_read] = '\0';
		if (ft_strchr((buffer), '\n'))
		{
			i = ft_strend(buffer);
			*s_buffer = ft_substr(buffer, i + 1, BUFFER_SIZE);
			return (ft_substr(buffer, 0, i + 1));
		}
	}
	if(*s_buffer) //se a estatica contem conteudo
	{
		if (ft_strchr(*s_buffer, '\n'))
		{
			i = ft_strend(*s_buffer);
			buffer = ft_substr(*s_buffer, 0, i + 1);
			*s_buffer = ft_substr(*s_buffer, i + 1, BUFFER_SIZE);
		}
		else
		{
			i = ft_strend(*s_buffer);
			buffer = ft_substr(*s_buffer, 0, i + 1);
		}
	}
	if (!buffer)
		return (NULL);
	return (buffer);
}

int ft_strend(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	return (NULL);
}
