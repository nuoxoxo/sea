/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    easy_putn(unsigned int n);
int     is_prime(unsigned int n);
int     easy_atoi(char *s);

int     main(int ac, char **av)
{
    unsigned int    n;
    unsigned int    i;
    unsigned int    tt;
    
    if (ac != 2 || easy_atoi(av[1]) == -1 || easy_atoi(av[1]) < 2)
    {
        write(1, "0", 1);
        write(1, "\n", 1);
        return 0;
    }

    n = easy_atoi(av[1]);
    tt = 0;
    i = 2;
    while (i <= n)
    {
        if (is_prime(i))
            tt += i;
        i++;
    }
    easy_putn(tt);
    write(1, "\n", 1);
    return tt;
}

void    easy_putn(unsigned int n)
{
    char    c;

    if (n < 10)
    {
        c = n + '0';
        write(1, &c, 1);
    }
    else
    {
        easy_putn(n / 10);
        c = n % 10 + '0';
        write(1, &c, 1);
    }
}

int     easy_atoi(char *s)
{
    int tt, i;
    tt = i = 0;

    if (s[0] == '-')
        return -1;
    while (s[i])
    {
        if (!(s[i] <= '9' && s[i] >= '0'))
            return -1;
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return tt;
}

int     is_prime(unsigned int n)
{
    unsigned int    div = 3;
    
    if (n < 2)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    else if (n % 2 == 0 || n % 3 == 0)
        return 0;
    while (div * div <= n)
    {
        if ((n % div) == 0)
            return 0;
        div += 2;
    }
    return 1;
}
