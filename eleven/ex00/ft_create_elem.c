/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

t_list  *ft_create_elem(void *data)
{
        t_list  *elem;

        elem = malloc(sizeof(t_list));
        if (!elem)
                return (NULL);
        elem->data = data;
        elem->next = NULL;
        return (elem);
}

/*

//  DRIVE

#include    <stdio.h>

int     main()
{
        char        data_1;
        int         data_2;

        t_list      *list_1;
        t_list      *list_2;
        
        data_1 = 'H';
        list_1 = ft_create_elem(&data_1);
        printf("list[0].data :  (char) %c\n", *(char*)list_1->data);

        data_2 = 1024;
        list_2 = ft_create_elem(&data_2);
        printf("list[1].data :  (int) %d\n", *(int*)list_2->data);
}

*/
