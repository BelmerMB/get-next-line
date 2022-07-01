/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/30 19:12:18 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	r_read;
	char		*buff;

	if(fd >= 1024 || fd < 0 || BUFFER_SIZE < 0 )//se for negativo deu falha no open, minha definição que fd vai de 0 até 1024
		return (NULL);//com ulimit -aH posso verificar o tamanho (fd), e modificando um arquivo especial mudo o tamanho
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));//alloca memoria para string com \0
	if (!buff)
		return (NULL);
	if (!(r_read = read (fd, buff, BUFFER_SIZE)) || r_read == -1) //atenção, se for 0 retorna 0. cuidado com -1
	{
		free (buff);
		return (NULL);
	}
	ft_next(fd, r_read);
		buff[r_read] = '\0';//coloca na ultima posição, NÃO vai ser utilizada aqui!!!!
	return (buff);
}

static void	ft_next(int fd, char *buffer)
{
	int	return_read;

	while (return_read)
	{
		
		return_read = read(fd, buffer, BUFFER_SIZE);
	}
}
