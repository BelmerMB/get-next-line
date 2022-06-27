/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/27 17:44:52 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if(fd >= 1024 || fd < 0 || BUFFER_SIZE < 0 )//se for negativo deu falha no open, minha definição que fd vai de 0 até 1024
		return (NULL);//com ulimit -aH posso verificar o tamanho (fd), e modificando um arquivo especial mudo o tamanho
	
}


// read (int fd, void* buf, size_t cnt);
/*
Parameters:

    fd: file descriptor
    buf: buffer to read data from
    cnt: length of buffer

Returns: How many bytes were actually read

    return Number of bytes read on success
    return 0 on reaching end of file
    return -1 on error
    return -1 on signal interrupt
*/