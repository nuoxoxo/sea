/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "utils.h"

//#   include <stdio.h>

void    display_tail(char *s);
int     file_size_line(char *fiilename);

int     main(int ac, char **av)
{
        int     i;

        if (ac < 2) return (0);
        i = 1;
        while (av[i])
        {
            if (ac > 2)
            {
                write(1, "==> ", 4);
                write(1, av[i], len(av[i]));
                write(1, " <==\n", 5);
            }
            display_tail(av[i]);
            if (i != ac - 1)   write(1, "\n", 1);
            i++;
        }
}

void    display_tail(char *filename)
{ 
        char    buf;
        int     fd;
        int     size;
        int     count;
        int     offset;

        fd = open(filename, O_RDONLY);
        if (fd < 0) return ;
        offset = 0;
        size = file_size_line(filename);

        if (size > 10)  offset = size - 1 - 10;
        count = 0;
        while (read(fd, &buf, 1))
        {
            if (count > offset)    write(1, &buf, 1);
            if (buf == '\n' && count <= offset)
                count++;
        }
        close(fd);
}

int     file_size_line(char *filename)
{
        char    c;
        int     fd;
        int     size;

        size = 0;
        fd = open(filename, O_RDONLY);
        while (read(fd, &c, 1))
        {
            if (c == 0 || c == '\n')
                size++;
        }
        return (size);
}
