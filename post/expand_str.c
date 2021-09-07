/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    expand_str(char *s);
int     is_word(char c);

// DRIVE

int     main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && !av[1]))
    {
        write(1, "\n", 1);
        return (-1);
    }
    expand_str(av[1]);
    return 0;
}

//

void    expand_str(char *s)
{
    int count;
    int i = 0;
    int is_start = 0;
    while (s[i])
    {
        count = 0;
        while (s[i] == 32 || (s[i] < 14 && s[i] > 8))
        {
            count++;
            if (!i)
                is_start = 1;
            i++;
        }
        if (count && !is_start && s[i])
            write(1, "   ", 3);
        while (is_word(s[i]))
        {
            write(1, &s[i], 1);
            i++;
        }
        is_start = 0;
    }
    write(1, "\n", 1);
}

int     is_word(char c)
{
    if (c == 33 || (c < 127 && c > 34))
        return 1;
    return 0;
}

