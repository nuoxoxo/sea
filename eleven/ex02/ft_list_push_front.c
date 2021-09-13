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
        t_list  *ptr;

        ptr = *begin_list;
        if (!ptr)
            *begin_list = ft_create_elem(data);
        else
        {
            ptr = ft_create_elem(data);
            ptr->next = *begin_list;
            *begin_list = ptr;
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

        //ptr = NULL;   //  <----   w/o this line the other main (push back) wont work
        ft_list_push_front(&ptr, &data1);
        printf("\nhead->data was : %c\n\n", *(char*)ptr->data);
        
        ft_list_push_front(&ptr, &data2);
        printf("head->data is  : %i\n", *(int*)ptr->data);
        printf("head->data->next->data is : ");
        printf("%c\n\n", *(char*)ptr->next->data);
}

*/
