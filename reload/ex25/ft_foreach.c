/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

void    ft_foreach(int *tab, int length, void(*f)(int));
void    pnbr(int n);
void    pn(int n);

// DRIVE

#include <unistd.h>

int     main()
{
        int     arr[] = {0, -64, 512, -1024, 2147483647, -2147483648};
        ft_foreach(arr, 6, &pnbr);
}

*/

void    ft_foreach(int *tab, int length, void(*f)(int))
{
        int     i;

        i = 0;
        while (i < length)
        {
                f(tab[i]);
                i++;
        }
}

/*

void    pn(int num)
{
        long    n;
        char    c;

        n = num;
        if      (n < 0)
        {
                n *= -1;
                write(1, "-", 1);
        }
        if      (n < 10 && n >= 0)
        {
                c = n + '0';
                write(1, &c, 1);
        }
        else
        {
                pn(n / 10);
                c = n % 10 + '0';
                write(1, &c, 1);
        }
}

void    pnbr(int n)
{
        pn(n);
        write(1, "\n", 1);
}
*/
