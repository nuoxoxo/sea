/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long    ops(int a, int b, long(*f)(int, int));
long    calc(int a, int b, char c);
long    ft_mult(int a, int b);
long    ft_add(int a, int b);
long    ft_sub(int a, int b);
long    ft_div(int a, int b);
long    ft_mod(int a, int b);
int     ft_atoi(char *s);
void    putlong(long n);

int     main(int argc, char **argv)
{
    char    c;
    long    n;
    int     L;
    int     R;

    if (argc != 4)
        return (0);
    c = *argv[2];
    L = ft_atoi(argv[1]);
    R = ft_atoi(argv[3]);
    n = calc(L, R, c);
    putlong(n);
    write(1, "\n", 1);
    return (0);
}

long    calc(int L, int R, char c)
{
    int n;

    n = 0;
    if (R == 0 && (c == '/' || c == '%'))
    {
        if (c == '/')
            write(1, "Stop : division by zero", 23);
        if (c == '%')
            write(1, "Stop : modulo by zero", 21);
        return (n);
    }
    if (c == '+')
        n = ops(L, R, &ft_add);
    else if (c == '-')
        n = ops(L, R, &ft_sub);
    else if (c == '*')
        n = ops(L, R, &ft_mult);
    else if (c == '/')
        n = ops(L, R, &ft_div);
    else if (c == '%')
        n = ops(L, R, &ft_mod);
    return (n);
}

long    ops(int a, int b, long(*f)(int, int))
{
        return (f(a, b));
}

int     ft_atoi(char *s)
{
    int sign = 1;
    int tt, i;
    tt = i = 0;
    while (s[i] == ' ' || (s[i] < 14 && s[i] > 8))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')    sign *= -1;
        i++;
    }
    while (s[i] <= '9' && s[i] >= '0')
    {
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return (sign * tt);
}

void    putlong(long n)
{
        char    c;

        if (n < 0)
        {
                n *= -1;
                write(1, "-", 1);
        }
        if (n < 10 && n >= 0)
        {
                c = n + '0';
                write(1, &c, 1);
        }
        else
        {
                putlong(n / 10);
                c = n % 10 + '0';
                write(1, &c, 1);
        }
}
