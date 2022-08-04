/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bot_elmer <bot_elmer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:55:22 by emetras-          #+#    #+#             */
/*   Updated: 2022/07/30 14:27:27 by bot_elmer        ###   ########.fr       */
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
	buf = get_next_line(0);  
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
	
	// buf = get_next_line(fd);  
	// printf("%s", buf);
	// free(buf);

    close(fd);
    return (0);
}