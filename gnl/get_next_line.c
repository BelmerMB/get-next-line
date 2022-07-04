/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/04 06:32:01 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(int fd, char *buffer, int read_c);
int		ft_putend(char *buffer);
// static int	str_len_nl(char *s, char crt);

char	*get_next_line(int fd)
{
	int				r_read;
	char		*buff;

	if(fd >= 1024 || fd < 0 || BUFFER_SIZE < 0 )//se for negativo deu falha no open, minha definição que fd vai de 0 até 1024
		return (NULL);//com ulimit -aH posso verificar o tamanho (fd), e modificando um arquivo especial mudo o tamanho
	buff = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));//alloca memoria para string com \0
	if (!buff)
		return (NULL);
	if (!(r_read = read(fd, buff, BUFFER_SIZE))) //atenção, se for 0 retorna 0. pensar no return -1 read
	{
		free (buff);
		return (NULL);
	}
	buff[r_read] = '\0';
	buff = ft_next(fd, buff, r_read);
	return (buff);
}

static char	*ft_next(int fd, char *buffer, int read_c)
{
	char	flag; //flag para achar o '\n' de new line
	char	*phrase;
	int		size;
	char	*temp;

	flag = 0;
	if (!read_c)
		return (buffer);
	phrase = ft_strjoin("\0", buffer); 
	// read_c = read(fd, buffer, BUFFER_SIZE);
	while (read_c && !flag)
	{
		if((ft_strrchr(phrase, '\n'))) //procura se tem o \n, se tiver entra no if
		{
			flag = 1;
			size = ft_putend(phrase);
			phrase[size +1] = '\0';
		}
		// phrase[read_c +1] = '\0';  //colocar +1
		if (!flag)
		{
			temp = phrase;  //amarzeno o ponteiro para não perder a referência
			read_c = read(fd, buffer, BUFFER_SIZE);
			phrase = ft_strjoin(phrase, buffer);//passei para depois do if
			free(temp); //limpo o ponteiro para não dá vazamento
		}
	}
	// phrase = ft_strjoin(phrase, buffer);
	free(buffer);
	return (phrase);
}

int ft_putend(char *buffer)
{
	int i;

	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}
// static int str_len_nl(char *s, char crt)
// {
// 	int	i;

// 	i = 0;
// 	while(*s != '\0' && *s != crt)
// 		i++;
// 	return (i);
// }
