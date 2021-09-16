/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    sort_int_tab(int *tab, unsigned int size)
{
        int             temp;
        unsigned int    i;

        if (size < 2)   return ;
        i = 0;
        while (i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                i = 0;
            }
            else    i++;
        }
}

/*

// DRIVE

#include    <stdlib.h>
#include    <stdio.h>

void    sort_put_arr(int *tab, unsigned int size);

int     main()
{
        unsigned int    size = 9;
        int             arr1[] = {1024, 64, -6, 0, 512, 4, 1, 2, 256};
        sort_put_arr(arr1, size);

        int             arr2[] = {8, 1, 7, 6, 0, 9, 4, 5, 2};
        sort_put_arr(arr2, size);

        int             arr3[] = {0};
        sort_put_arr(arr3, 1);
        
        int             arr4[] = {};
        sort_put_arr(arr4, 0);

        int             arr5[] = {1, 0};
        sort_put_arr(arr5, 2);
}

void    sort_put_arr(int *tab, unsigned int size)
{
        unsigned int        i = 0;
        printf("\nOriginal array : \n");
        while (i < size)    printf("%i ", tab[i++]);
        printf("\n\n");
        printf("Now it becomes : \n");
        sort_int_tab(tab, size);
        i = 0;
        while (i < size)    printf("%i ", tab[i++]);
        printf("\n\n");
}

*/
