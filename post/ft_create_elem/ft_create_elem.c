/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
        t_list  *elem;

        elem = malloc(sizeof(t_list));
        if (!elem)  return (NULL);
        elem->data = data;
        elem->next = NULL;
        return (elem);
}

/*

//  DRIVE

#include <stdio.h>

int     main(int argc, char **argv)
{
        (void)      argc;
        char        *data;
        char        data_1;
        int         data_2;
        t_list      *list, *list_1, *list_2;
        
        data = argv[1];
        data_1 = 'R';
        data_2 = 1024;

        list = ft_create_elem(data);
        list_1 = ft_create_elem(&data_1);
        //  '&' is not needed if type is 'char*'
        list_2 = ft_create_elem(&data_2);
        
        printf("list->data : %s (argv[1])\n", (char*)list->data);
        printf("list->data : %c (char)\n", *(char*)list_1->data);
        //  only '*(char*)' works, '(char)lst->data' doesn't work
        printf("list->data : %i (int)\n", *(int*)list_2->data);
}

*/
