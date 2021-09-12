/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_usage(char *c)
{
    /*
    if (c == "/")
        write(1, "Stop : division by zero", 23);
    else if (c == "%")
        write(1, "Stop : modulo by zero", 21);
    else
        write(1, "error : only [ - + * / % ] are accepted.", 10);
    */
    write(1, "error : only [ - + * / % ] are accepted.", 40);
    return ;
}
