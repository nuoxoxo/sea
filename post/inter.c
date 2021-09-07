/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    inter(char *L, char *R);
int     seen(char *L, int x);

int     main(int argc, char **argv)
{
    if (argc != 3)  return (-1);
    inter(argv[1], argv[2]);
    return (0);
}

void    inter(char *L, char *R)
{
    int i, j;

    i = 0;
    while (L[i])
    {
        j = 0;
        while (R[j])
        {
            if (L[i] == R[j])
            {
                write(1, &L[i], 1);
                break;
            }
            j++;
        }
        i++;
        while (seen(L, i))
            i++;
    }
}

int     seen(char *L, int x)
{
    int i = 0;
    if (!x) return 0;
    while (i < x)
    {
        if (L[i] == L[x])
            return 1;
        i++;
    }
    return 0;
}
