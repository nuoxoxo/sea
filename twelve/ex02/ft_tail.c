/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "utils.h"

//  #   include <stdio.h>

void    msg(char *filename, int opcode);
void    display_filename(char *filename);
void    display_default(void);

int     display_tail(char *filename, int n, int argc);
int     count_lines_in_file(char *filename);
int     verify_argv(int ac, char **av);
int     check_if_only_num(char *s);

// DRIVE

int     main(int ac, char **av)
{
        int     i;
        
        if (verify_argv(ac, av) != 0) return (0);
        i = 1;
        while (av[i])
        {
            if (display_tail(av[i], 10, ac) == 1 && i != ac - 1)
                write(1, "\n", 1);
            i++;
        }
        return (0);
}

int     display_tail(char *filename, int offset, int ac)
{ 
        char    buf;
        int     fd;
        int     size;
        int     count;
        int     target;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return (0);
        }

        if (ac > 2) display_filename(filename);
        target = 0;
        size = count_lines_in_file(filename);
        if (size > offset)  target = size - 1 - offset;
        count = 0;
        while (read(fd, &buf, 1))
        {
            if (count > target)    write(1, &buf, 1);
            if (buf == '\n' && count <= target)
                count++;
        }
        close(fd);
        return (1);
}

int     verify_argv(int ac, char **av)
{
        if (ac < 2) display_default();
        if (av[1][0] == '-')
        {
            if (!av[1][1])
            {
                msg(av[1], 0);
                return (1);
            }
            if (av[1][1] == '-' && !av[1][2])   display_default();
            if (av[1][1] != 'c')
            {
                msg(av[1], 1);
                return (1);
            }
            if (av[1][1] == 'c')
            {
                if (!av[2])
                {
                    msg(av[1], 2);
                    return (1);
                }
                if (!check_if_only_num(av[2]))
                {
                    msg(av[2], 3);
                    return (1);
                }
                if (check_if_only_num(av[2]) && !av[3]) display_default();
            }
        }
        return (0);
}

int     count_lines_in_file(char *filename)
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
        close(fd);
        return (size);
}

void    display_filename(char *filename)
{
        write(1, "==> ", 4);
        write(1, filename, len(filename));
        write(1, " <==\n", 5);
}

void    display_default(void)
{
        char    c;
        
        while (read(STDIN_FILENO, &c, 1))
            continue;
}

int     check_if_only_num(char *s)
{
        int     i;

        i = 0;
        if (s[i] == '-')    i += 1;
        while (s[i])
        {
            if (s[i] < 48 || s[i] > 57) return (0);
            i++;
        }
        return (1);
}
