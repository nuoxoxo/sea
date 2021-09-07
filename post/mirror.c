/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    mirror(char c);
int     is_lo(char c);
int     is_up(char c);

int     main(int argc, char **argv)
{
    int     i;
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (-1);
    }
    i = 0;
    while (argv[1][i])
    {
        mirror(argv[1][i]);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}

void    mirror(char c)
{
    char    x;
    if (is_up(c))
    {
        x = 'Z' + 'A' - c;
        write(1, &x, 1);
    }
    else if (is_lo(c))
    {
        x = 'z' + 'a' - c;
        write(1, &x, 1);
    }
    else
        write(1, &c, 1);
}

int     is_up(char c)
{
    if (c <= 'Z' && c >= 'A')   return 1;
    return 0;
}

int     is_lo(char c)
{
    if (c <= 'z' && c >= 'a')   return 1;
    return 0;
}
