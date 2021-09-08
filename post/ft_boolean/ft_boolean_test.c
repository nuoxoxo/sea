/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_boolean.h"

void    ps(char *s)
{
        while (*s)  write(1, s++, 1);
}

t_bool  ft_is_even(int n)
{
        return  ((EVEN(n)) ? TRUE : FALSE);
}

int     main(int argc, char **argv)
{
        (void) argv;
        if (ft_is_even(argc - 1) == TRUE)   ps(EVEN_MSG);
        else    ps(ODD_MSG);
        return  (SUCCESS);
}
