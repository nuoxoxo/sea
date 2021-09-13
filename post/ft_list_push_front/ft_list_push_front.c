/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

t_list  *ft_create_elem(void *d);

void    ft_list_push_front(t_list **begin_list, void *data)
{
        t_list  *thing;

        if (!begin_list)
            *begin_list = ft_create_elem(data);
        else
        {
            thing = ft_create_elem(data);
            thing->next = *begin_list;
            *begin_list = thing;
        }
}

t_list  *ft_create_elem(void *data)
{
        t_list  *thing;

        thing = malloc(sizeof(t_list));
        if (!thing)
            return (NULL);
        thing->data = data;
        thing->next = NULL;
        return (thing);
}

/*

// DRIVE

#include    <stdio.h>

int     main(int argc, char **argv)
{
        (void)  argc;
        
        char    data1 = *argv[1];
        int     data2 = atoi(argv[2]);
        t_list  *thing;

        thing = ft_create_elem(&data1);
        printf("\nhead->data was : %c\n\n", *(char*)thing->data);
        
        ft_list_push_front(&thing, &data2);
        printf("head->data is  : %i\n", *(int*)thing->data);
        printf("head->data->next->data is : ");
        printf("%c\n\n", *(char*)thing->next->data);
}

*/
