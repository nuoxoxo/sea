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
    int s = 0;
    int e = -3;
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

//

int     *ft_rrange(int start, int end)
{
    int     diff;
    int     *p;

    diff = start - end >= 0 ? start - end + 1 : end - start + 1;
    if (!(p = malloc(sizeof(int) * diff)))  return NULL;
    while (diff--)
        p[diff] = start - end >= 0 ? start-- : start++;
    return p;
}
