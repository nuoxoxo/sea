/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
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

void    ft_list_push_back(t_list **begin_list, void *data)
{
        t_list  *ptr;

        ptr = *begin_list;
        if (!ptr)
            *begin_list = ft_create_elem(data);
        else
        {
            ptr = *begin_list;
            while (ptr->next) 
                ptr = ptr->next;
            ptr->next = ft_create_elem(data);
        }
}

t_list  *ft_create_elem(void *data)
{
        t_list  *ptr;

        ptr = malloc(sizeof(t_list));
        if (!ptr)
            return (NULL);
        ptr->data = data;
        ptr->next = NULL;
        return (ptr);
}

/*

// DRIVE

#include    <stdio.h>

int     main(int argc, char **argv)
{
        (void)  argc;
        char    data1 = *argv[1];
        int     data2 = atoi(argv[2]);
        t_list  *ptr;
        
        ptr = NULL;
        ft_list_push_back(&ptr, &data1);
        printf("\nlist->data is : %c\n", *(char*)ptr->data);
        printf("list->next->data is empty : %p\n\n", ptr->next);

        ft_list_push_back(&ptr, &data2);
        printf("list->data is : %c\n", *(char*)ptr->data);
        printf("list->next->data is : %i\n\n", *(int*)ptr->next->data);
}

*/
