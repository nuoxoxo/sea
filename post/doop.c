/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_atoi(char *s);
int     is_wsp(char c);
int     is_num(char c);

int     main(int argc, char **argv)
{
    char    c;
    int     L;
    int     R;
    
    if (argc != 4)
    {
        printf("\n");
        return (-1);
    }
    
    c = *argv[2];
    L = ft_atoi(argv[1]);
    R = ft_atoi(argv[3]);
    switch(c)
    {
        case    '+':
            printf("%i", L + R);
            break;
        case    '-':
            printf("%i", L - R);
            break;
        case    '*':
            printf("%i", L * R);
            break;
        case    '/':
            printf("%i", L / R);
            break;
        case    '%':
            printf("%i", L % R);
            break;
    }
    printf("\n");
    return 0;
}

int     ft_atoi(char *s)
{
    int sign = 1;
    int tt, i;
    tt = i = 0;
    while (is_wsp(s[i]))    i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')    sign *= -1;
        i++;
    }
    while (is_num(s[i]))
    {
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return (sign * tt);
}

int     is_num(char c)
{
    if (c <= '9' && c >= '0')   return 1;
    return 0;
}

int     is_wsp(char c)
{
    if (c == ' ' || (c < 14 && c > 8))  return 1;
    return 0;
}
