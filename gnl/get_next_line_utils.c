/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:15 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/14 16:33:01 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin(const char *s1, char const *s2)
// {
// 	size_t	size;
// 	size_t	index;
// 	char	*ptr;

// 	index = 0;
// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	ptr = (char *) malloc((size +1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	while (*s1)
// 		ptr[index++] = *s1++;
// 	while (*s2)
// 		ptr[index++] = *s2++;
// 	ptr[index] = '\0';
// 	return (ptr);
// }

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		len = 1;
		start = 0;
	}
	else if (len + start > s_len)
		len = s_len - start + 1;
	else
		len = len + 1;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s[start], len);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size -1] = '\0';
	}
	return (srclen);
}

void	*ft_memcpy( void *dest, const void *src, size_t count )
{
	unsigned char	*source;
	unsigned char	*des;
	size_t			i;

	i = 0;
	source = (unsigned char *) src;
	des = (unsigned char *)dest;
	while (i < count)
	{
		des[i] = source [i];
		i++;
	}
	return ((void *) des);
}
