/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa(int   n);
int     count_digit(long    n);

/// DRIVE

#include <stdio.h>

int     main()
{
    printf("%s\n", ft_itoa(-42));
    printf("%s\n", ft_itoa(42));
}

char    *ft_itoa(int   n)
{
    long    num;
    char    *res;
    int     i;

    num = n;
    if (n == 0)
    {
        res = "0";
        return (res);
    }

    i = count_digit(num);
    res = malloc(sizeof(char) * (i + 1));
    if (!res)
        return NULL; 
    
    res[i--] = 0;
    if (n < 0)
    {
        res[0] = '-';
        n *= -1;
    }
    while (n > 0)
    {
        res[i] = n % 10 + '0';
        n /= 10;
        i--;
    }
    return res;
}

int     count_digit(long    n)
{
    int i = 0;

    if (n < 0)
    {
        n *= -1;
        i += 1;
    }
    while (n > 0)
    {
        i++;
        n /= 10;
    }
    return i;
}
