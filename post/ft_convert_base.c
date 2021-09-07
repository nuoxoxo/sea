/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// str_base to int ----> int to str_base_to

char    *ft_convert_base(char *nbr, char *base_from, char *base_to);
char    *ft_itoa_to_base(int num, char *base_to);
int     ft_atoi_base(char *s, char *b);
int     find_index_in_base(char c, char *b);
int     count_digits(long n, int rad);
int     base_is_valid(char *b);
int     len(char *s);

// DRIVE

#include <stdio.h>

int main()
{
    printf(" \n");
    printf(" %s\n", ft_convert_base("10100001110101011110110010","01","0123456789abcdef"));
    printf(" %s\n\n",ft_convert_base("011010101110010101001001110","01","0123456789abcdef"));
    printf(" %s\n", ft_convert_base("-10100001110101011110110010","01","0123456789abcdef"));
    printf(" %s\n\n",ft_convert_base("-011010101110010101001001110","01","0123456789abcdef"));
    printf(" %s\n", ft_convert_base("13255340", "0123456789", "0123456789abcdef"));
    printf(" %s\n", ft_convert_base("35.;5|", "0123456789abcd.;|", "0123456789abc"));
    printf(" %s\n", ft_convert_base("cb818f6", "0123456789abcdef", "0|23456789."));
    printf(" %s\n", ft_convert_base("6301063", "01234567", "01234."));
    printf(" %s\n\n",ft_convert_base("-2147483648", "0123456789", "01"));
    printf(" %s\n",ft_convert_base("20041", "01234567", "0123456789abcdef"));
    printf(" %s\n",ft_convert_base("-10302", "01234", "0123456"));  return (0);
}

//

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    unsigned int    n;

    if (!base_is_valid(base_from) || !base_is_valid(base_to))
        return (NULL);
    n = ft_atoi_base(nbr, base_from);
    return  (ft_itoa_to_base(n, base_to));
}

char    *ft_itoa_to_base(int num, char *base_to)
{
    char    *str;
    long    n;
    int     i;
    int     rad;

    if (num == 0)
    {
        if (!(str = malloc(sizeof(char))))
            return NULL;
        str[0] = base_to[0];
        return (str);
    }

    n = num;
    rad = len(base_to);
    i = count_digits(n, rad);

    if (!(str = malloc(sizeof(char) * (i + 1))))
        return NULL;
    if (n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    str[i--] = 0;
    while (n)
    {
        str[i] = base_to[n % rad];
        n /= rad;
        i--;
    }
    return (str);
}

int     count_digits(long n, int rad)
{
    int i = 0;
    if (n < 0)
    {
        n *= -1;
        i += 1;
    }
    
    while (n != 0)
    {
        n /= rad;
        i++;
    }
    return (i);
}

int    ft_atoi_base(char *s, char *b)
{
    int     sign;
    int     rad;
    int     tt;
    int     i;

    sign = 1;
    tt = 0;
    i = 0;
    rad = len(b);

    while (s[i] == ' ' || (s[i] < 14 && s[i] > 8))
        i++;
    while (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')    sign *= -1;
        i++;
    }
    while (find_index_in_base(s[i], b) != -1)
    {
        tt = tt * rad + find_index_in_base(s[i], b);
        i++;
    }
    return  (sign * tt);
}

int     find_index_in_base(char c, char *b)
{
    int     i;

    i = 0;
    while (b[i])
    {
        if (b[i] == c)  return (i);
        i++;
    }
    return (-1);
}

int     base_is_valid(char *b)
{
    int     len;
    int     i;
    int     j;

    len = len(b);
    if (len < 2)    return (0);
    
    i = 0;
    while (i < len)
    {
        if (b[i] == '+' || b[i] == '-'
            || b[i] == ' ' || (b[i] < 14 && b[i] > 8))
            return (0);
        i++;
    }
    i = 0;
    while (i < len - 1)
    {
        j = i + 1;
        while (j < len)
        {
            if (b[i] == b[j++])     return (0);
        }
        i++;
    }
    return (1);
}

int     len(char *s)
{
    int i = 0;
    while (s[i])    i++;
    return (i);
}
