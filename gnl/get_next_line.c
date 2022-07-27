/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/25 18:30:08 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_next(int fd, char **s_buffer, char *buffer);
static char	*ft_get_line(char **s_buffer, char *bff, int fd);

char	*get_next_line(int fd)
{
	static char	*s_buff;
	char		*buff;

	if(fd > 1023 || fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (!s_buff)
		s_buff = ft_strjoin("", ""); //inicializa a statica
	buff = ft_next(fd, &s_buff, buff);
	return (buff);
}

static char	*ft_next(int fd, char **s_buffer, char *buffer)
{
	char	*tmp;
	char	*line;
	int		sz_read;

	sz_read = 1;
	while((!ft_strchr(*s_buffer, '\n')) && sz_read > 0)
	{
		sz_read = read(fd, buffer, BUFFER_SIZE);
		buffer[sz_read] = '\0';
		if(!sz_read)
			break;
		tmp = *s_buffer;
		*s_buffer = ft_strjoin(tmp, buffer);
		free (tmp);
	}
	// if (sz_read == -1) //pode quebrar por vazamento
	// 		return (NULL);
	line = ft_get_line(s_buffer, buffer, sz_read);
	return (line);
}

static char *ft_get_line(char **s_buffer, char *bff, int read)
{
	int	i;
	char *tmp;

	i = 0;
	while(*(*s_buffer + i) != '\n' && *(*s_buffer + i) != '\0')
		i++;
	if (!read && !i) //se for 0 na leitura e 0 de tamanho return null
	{
		tmp = *s_buffer;
		free (tmp);
		*s_buffer = NULL;
		free (bff);
		return (NULL);
	}
	tmp = bff;
	bff = ft_substr(*s_buffer, 0, i + 1);
	free (tmp);
	tmp = *s_buffer;
	*s_buffer = ft_substr(*s_buffer, i + 1, ft_strlen(*s_buffer));  //buffer continua reachable apos EOF
	free (tmp);
	return (bff);
}

char	*ft_strchr(const char *s, int c) //preciso da static? 
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
