/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_count_if(char **tab, int(*f)(char *))
{
        int     counter = 0;
        int     i = 0;
        while   (tab[i])
        {
                if (f(tab[i]) == 1)
                {
                        counter++;
                }
                i++;
        }
        return (counter);
}

/*

// DRIVE

#include <stdio.h>

int     is_len_seven(char *s)
{
        int     i = 0;
        if (!s) return 0;
        while (s[i])    i++;
        if (i == 7)     return 1;
        return 0;
}

int     main(int argc, char **argv)
{
        (void)  argc;
        printf("%i\n", ft_count_if(argv, &is_len_seven));
}

*/
