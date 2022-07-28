/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:55:22 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/28 17:56:30 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

 int main(void)
{
    int     fd;
    char    *buf;

// single file test
    fd = open("42_with_nl", O_RDONLY);
	buf = get_next_line(fd);  
	 printf("%s", buf);
	    free(buf);
		
	buf = get_next_line(fd);  
	printf("%s", buf);
	free(buf);
	
	// buf = get_next_line(fd);  
	// printf("%s", buf);
	// free(buf);
	
	// buf = get_next_line(fd);  
	// printf("%s", buf);
	// free(buf);
	
	// buf = get_next_line(fd);  
	// printf("%s", buf);
	// free(buf);

    close(fd);
    return (0);
}