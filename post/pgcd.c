/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// no malloc no free 

unsigned int    find_next_cd(unsigned int cd, unsigned int a, unsigned int b);
unsigned int    gcd(unsigned int a, unsigned int b);

int     main(int argc, char **argv)
{
    unsigned int    a, b;

    if (argc != 3)
    {
        printf("\n");
        return (-1);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%i %i \n", a, b);
    if (!a || !b)
    {
        printf("\n");
        return (-1);
    }
    printf("%u\n", gcd(a, b));
}

//

unsigned int    gcd(unsigned int a, unsigned int b)
{
    int     cd;
    
    if (!a || !b)   return 0;
    cd = b > a ? a : b;
    return find_next_cd(cd, a, b);
}

unsigned int    find_next_cd(unsigned int cd, unsigned int a, unsigned int b)
{
    if (!(a % cd) && !(b % cd))
        return (cd);
    if (cd < 2)
        return 1;
    return (find_next_cd(cd - 1, a, b));
}

/*
int             atoi_positive(char *s)
{
    int     sign;
    int     tt;
    int     i;

    sign = 1;
    tt = 0;
    i = 0;
    while (s[i] == ' ' || (s[i] < 14 && s[i] > 8))
        i++;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] <= '9' && c >= '0')
    {
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return (sign * tt);
}
*/
