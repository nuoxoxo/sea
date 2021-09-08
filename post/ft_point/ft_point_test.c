/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"

void    set_point(t_point   *point)
{
    point->x = 42;
    point->y = 21;
}

#include <stdio.h>

int     main(void)
{
    t_point     point;
    set_point(&point);
    printf("point.x : %i\n", point.x);
    printf("point.y : %i\n\n", point.y);

    t_point     another_point;
    set_point(&another_point);
    printf("another_point.x : %i\n", another_point.x);
    printf("another_point.y : %i\n", another_point.y);

    return  (0);
}
