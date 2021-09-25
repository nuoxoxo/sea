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


void    msg(char *filename, int opcode);
void    display_filename(char *filename);
void    display_stdout(void);
int     display_c_tail(char *filename, int offset, int ac);
int     display_c_head(char *filename, int offset, int ac);
int     display_default(char *filename, int argc);
int     count_size_of_file(char *filename, int mode);
int     verify_argv_minus(char **argv);
int     verify_argv(int ac, char **av);
int     check_if_only_num(char *s);
int     atoi_easy(char *s);

// DRIVE

int     main(int ac, char **av)
{
        int     offset;
        int     i;
        
        offset = 0;
        i = verify_argv(ac, av);
        if (!i)     return (0);
        if (i == 3)
        {
            offset = atoi_easy(av[2]);
            if (av[2][0] != '+')
            {
                if (offset < 0) offset *= -1;
                while (av[i])
                {
                    if (!display_c_tail(av[i], offset, ac) && i != ac - 1)
                        write(1, "\n", 1);
                    i++;
                }
                return (0);
            }
            else
            {
                while (av[i])
                {
                    if (!display_c_head(av[i], offset, ac) && i != ac - 1)
                        write(1, "\n", 1);
                    i++;
                }
                return (0);
            }
        }
        while (av[i])
        {
            if (!display_default(av[i], ac) && i != ac - 1)
                write(1, "\n", 1);
            i++;
        }
        return (0);
}

int     display_c_head(char *filename, int offset, int ac)
{
        char    c;
        int     fd;
        int     size;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return (0);
        }
        if (ac > 2) display_filename(filename);
        size = count_size_of_file(filename, 1);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= offset - 1)    write(1, &c, 1);
            else
                count++;
        }
        close(fd);
        return (1);
}

int     display_c_tail(char *filename, int offset, int ac)
{
        char    c;
        int     fd;
        int     size;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return (0);
        }
        if (ac > 2) display_filename(filename);
        size = count_size_of_file(filename, 1);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= size - offset) write(1, &c, 1);
            count++;
        }
        close(fd);
        return (1);
}

int     display_default(char *filename, int ac)
{ 
        char    c;
        int     fd;
        int     size;
        int     offset;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return (0);
        }
        if (ac > 2) display_filename(filename);
        offset = 10;
        size = count_size_of_file(filename, 0);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= size - offset) write(1, &c, 1);
            if (c == '\n' && count <= offset)
                count++;
        }
        close(fd);
        return (1);
}

int     verify_argv(int ac, char **av)
{
        if (ac < 2) display_stdout();
        if (av[1][0] == '-')
        {
            if (av[1][1] == '-' && !av[1][2])
                display_stdout();
            if (av[1][1] == 'c' && check_if_only_num(av[2]) && !av[3])
                display_stdout();
            return verify_argv_minus(av);
        }
        return (1);
}

int     verify_argv_minus(char **av)
{
        if (!av[1][1])
        {
            msg(av[1], 0);
            return (0);
        }
        if (av[1][1] != 'c')
        {
            msg(av[1], 1);
            return (0);
        }
        if (av[1][1] == 'c')
        {
            if (!av[2])
            {
                msg(av[1], 2);
                return (0);
            }
            if (!check_if_only_num(av[2]))
            {
                msg(av[2], 3);
                return (0);
            }
            return (3);
        }
        return (1);
}

int     count_size_of_file(char *filename, int mode)
{
        char    c;
        int     fd;
        int     size;

        size = 0;
        fd = open(filename, O_RDONLY);
        if (mode == 0)
        {
            //size = 0;
            //fd = open(filename, O_RDONLY);
            while (read(fd, &c, 1))
            {
                if (c == 0 || c == '\n')
                    size++;
            }
            //close(fd);
        }
        else if (mode == 1)
        {
            while (read(fd, &c, 1)) 
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

void    display_stdout(void)
{
        char    c;
        
        while (read(STDIN_FILENO, &c, 1))
            continue;
}

int     check_if_only_num(char *s)
{
        int     i;

        i = 0;
        if (s[i] == '-' || s[i == '+'])
            i += 1;
        while (s[i])
        {
            if (s[i] < 48 || s[i] > 57) return (0);
            i++;
        }
        return (1);
}
