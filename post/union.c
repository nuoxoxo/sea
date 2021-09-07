/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// + efficient solve might exist

void    ft_union(char *s);
int     seen_so_far(char *s, int index);
int     seen_in_av1(char *s, char c);

int     main(int argc, char **argv)
{
    int i;
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (-1);
    }
    i = 0;
    while (argv[1][i])
    {
        if (!seen_so_far(argv[1], i))
            write(1, &argv[1][i], 1);
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (!seen_so_far(argv[2], i)
            && !seen_in_av1(argv[1], argv[2][i]))
            write(1, &argv[2][i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int     seen_so_far(char *s, int index)
{
    int i;
    
    if (!index) return 0;
    i = 0;
    while (i < index)
    {
        if (s[index] == s[i])  return 1;
        i++;
    }
    return 0;
}

int     seen_in_av1(char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (c == s[i])  return 1;
        i++;
    }
    return 0;
}
