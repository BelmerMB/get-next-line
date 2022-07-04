/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:24:15 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/03 02:54:28 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2) //apaguei o const do s1
{
	size_t	size;
	size_t	index;
	char	*ptr;

	index = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) ft_calloc(size +1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[index++] = *s1++;
	while (*s2)
		ptr[index++] = *s2++;
	ptr[index] = '\0';
	//free (s1); // adicional para gnl, libero o espaço do s1.
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = nmemb * size;
	if (nmemb <= 0 || size <= 0 || ((max / size) != nmemb))
		return (NULL);
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, '\0', max));
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 0)
	{
		str[n - 1] = (char) c;
		n--;
	}
	return (s);
}

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	last;

	last = -1;
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			last = index;
		index++;
	}
	if (s[index] == (char)c)
		last = index;
	if (last >= 0)
		return ((char *)&s[last]);
	return (NULL);
}