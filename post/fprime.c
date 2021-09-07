/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void            fprime(unsigned int n);
int             is_prime(unsigned int n);
unsigned int    find_next_prime(unsigned int n);

int     main(int ac, char **av)
{
    unsigned int    n;

    if (ac != 2 || (ac == 2 && !av[1]) || atoi(av[1]) < 0)
    {
        printf("\n");
        return (-1);
    }
    n = atoi(av[1]);
    fprime(n);
    return 0;
}

void    fprime(unsigned int n)
{
    unsigned int    div = 2;
    unsigned int    tmp = n;
    if (n == 1)
        printf("1\n");
    while (n != 0 && div <= tmp)
    {
        if (n % div == 0)
        {
            printf("%i", div);
            if (n / div != 1)
                printf("*");
            n /= div;
        }
        else
        {
            div = find_next_prime(div + 1);
        }
    }
}

unsigned int    find_next_prime(unsigned int n)
{
    if (is_prime(n))    return n;
    return find_next_prime(n + 1);
}

int is_prime(unsigned int n)
{
    unsigned int    div = 3;
    if (n < 2)  return 0;
    if (n == 2 || n == 3)   return 1;
    else if (!(n % 2) || !(n % 3))  return 0;
    while (div * div <= n)
    {
        if ((n % div) == 0) return 0;
        div += 2;
    }
    return 1;
}
