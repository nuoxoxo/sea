/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *str_init(long n, int base, char *ref);
char    *ft_itoa_base(int value, int base);
int     count_digits(long n, int base);
long    to_abs(long n);

/// DRIVE

#include <stdio.h>

int     main()
{
    printf(" -42 to dec : %s \n", ft_itoa_base(-42, 10));
    printf(" 42 to dec : %s \n\n", ft_itoa_base(42, 10));
    printf(" -42 to hex : %s \n", ft_itoa_base(-42, 16));
    printf(" 42 to hex : %s \n\n", ft_itoa_base(42, 16));

    printf(" -0 to dex : %s \n", ft_itoa_base(-0, 10));
    printf(" 0 to dec : %s \n", ft_itoa_base(0, 10));
    printf(" 0 to hex : %s \n\n", ft_itoa_base(0, 16));
    
    printf(" 512 to hex : %s \n", ft_itoa_base(512, 16));
    printf(" -1024 to bin : %s \n", ft_itoa_base(-1024, 2));
    printf(" -51299 to bin : %s \n", ft_itoa_base(-51299, 2));

    return 0 ;
}

//

char	*ft_itoa_base(int value, int base)
{
    char    *ref;
    char    *s;
    long    n;

    ref = "0123456789ABCDEF"; 
    if (base < 2 || base > 16)
        return NULL;
    if (!value)
    {
        if (!(s = malloc(sizeof(char))))
            return NULL;
        s = "0";
        return s;
    }
    n = value;
    s = str_init(n, base, ref);
    return s;
}

char    *str_init(long n, int base, char *ref)
{
    char    *s;
    int     i;

    if (base == 10 && n < 0)
    {
        i = count_digits(n, base);
        if (!(s = malloc(sizeof(char) * (i + 1))))
            return NULL;
        s[0] = '-';
        n = to_abs(n); // <----- w/o this line (-42, 10) will turn out (-s)
    }
    else
    {
        n = to_abs(n);
        i = count_digits(n, base);
        if (!(s = malloc(sizeof(char) * (i + 1))))
            return NULL;
    }
    s[i--] = 0;
    while (n)
    {
        s[i] = ref[n % base];
        n /= base;
        i--;
    }
    return (s);
}

int     count_digits(long n, int base)
{
    int i = 0;

    if (n < 0)
    {
        n *= -1;
        i += 1;
    }
    while (n)
    {
        i++;
        n /= base;
    }
    return i;
}

long        to_abs(long n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}
