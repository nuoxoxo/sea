/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l c m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    find_next_cm(unsigned int cm, unsigned int a, unsigned int b);
unsigned int    lcm(unsigned int a, unsigned int b);

// DRIVE

#include <stdio.h>

int     main(void)
{
    printf("42 : %u \n", lcm(42, 21));
    printf("0 : %u \n", lcm(99, 0));
    printf("43 : %u \n", lcm(1, 43));
    printf("42 : %u \n", lcm(2, 21));
    printf("360 : %u \n", lcm(72, 60));
    printf("403 : %u \n", lcm(31, 13));
    printf("1207 : %u \n", lcm(71, 17));
    printf("1680 : %u \n", lcm(112, 120));
    printf("8633 : %u \n", lcm(89, 97));
}

//

unsigned int    lcm(unsigned int a, unsigned int b)
{
    int     cm;
    if (!a || !b)   return 0;
    cm = a > b ? a : b;
    return find_next_cm(cm, a, b);
}

unsigned int    find_next_cm(unsigned int cm, unsigned int a, unsigned int b)
{
    if (!(cm % a) && !(cm % b))
        return (cm);
    return (find_next_cm(cm + 1, a, b));
}
