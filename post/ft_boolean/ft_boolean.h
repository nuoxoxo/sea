/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_BOOLEAN_H
# define    FT_BOOLEAN_H

# define    TRUE        1
# define    FALSE       0
# define    SUCCESS     0
# define    EVEN(n)     n % 2 == 0
# define    EVEN_MSG    "I have an even number of arguments.\n"
# define    ODD_MSG     "I have an odd number of arguments.\n"
# include   <unistd.h>
typedef     int t_bool;

#endif
