/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_rrange(int start, int end);

// DRIVE
#include <stdio.h>
int     main(void)
{
    int s = 1;
    int e = 3;
    int i = 0;
    int *p = ft_rrange(s, e);
    if (s - e <= 0)
    {
        while (i <= e - s)  printf("%i ", p[i++]);
    }
    else
    {
        while (i <= s - e)  printf("%i ", p[i++]);
    }
}

int     *ft_rrange(int start, int end)
{
    int     i;
    int     *p;
    int     diff = start - end;
    
    if (diff < 0)
    {
        if (!(p = malloc(sizeof(int) * (1 - diff))))    return NULL;
        i = 0;
        while (i <= -diff)
            p[i++] = end--;
        return p;
    }
    else if (diff > 0)
    {
        if (!(p = malloc(sizeof(int) * (diff + 1))))    return NULL;
        i = 0;
        while (i <= diff)
            p[i++] = end++;
        return p;
    }
    if (!(p = malloc(sizeof(int)))) return NULL;
    p[0] = 0;
    return p;
}
