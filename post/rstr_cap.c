/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    r_upper(char *s);

int     main(int argc, char **argv)
{
    int     i;
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 1;
    while (i < argc)
    {
        r_upper(argv[i]);
        i++;
    }
    return (0);
}

void    r_upper(char *s)
{
    int     i;
    i = 0;
    while (s[i])
    {
        if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] += 32;
        i++;
    }
    i = 0;
    while (s[i])
    {
        if (s[i] <= 'z' && s[i] >= 'a'
            && (!s[i + 1] || s[i + 1] == ' '
            || (s[i + 1] > 8 && s[i + 1] < 14)))
            s[i] -= 32;
        i++;
    }
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
}
