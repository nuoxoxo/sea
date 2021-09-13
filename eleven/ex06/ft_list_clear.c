/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

void    ft_list_clear(t_list **begin_list)
{
        t_list  *ptr;

        while   (*begin_list != NULL)
        {
                ptr = *begin_list;
                *begin_list = (*begin_list)->next;
                free(ptr);
        }
}

/*

// DRIVE

#include    <stdio.h>

void    ft_list_push_back(t_list **head, void *data);
t_list  *ft_create_elem(void *d);

int     main(int argc, char **argv)
{
        (void)  argc;
        
        char    data1 = *argv[1];
        char    data2 = *argv[2];
        char    data3 = *argv[3]; 
        char    data4 = *argv[4];
        char    data5 = *argv[5];
        t_list  *p;

        p = NULL;
        ft_list_push_back(&p, &data1);
        ft_list_push_back(&p, &data2);
        ft_list_push_back(&p, &data3);
        ft_list_push_back(&p, &data4);
        ft_list_push_back(&p, &data5);

        printf("\nBefore : \n\n[0] : %c\n", *(char*)p->data);
        printf("[1] : %c\n", *(char*)p->next->data);
        printf("[2] : %c\n", *(char*)p->next->next->data);
        printf("[3] : %c\n", *(char*)p->next->next->next->data);
        printf("[4] : %c\n\n", *(char*)p->next->next->next->next->data);

        ft_list_clear(&p);
        
        printf("After : \n\n%p\n\n", p);
}

void    ft_list_push_back(t_list **head, void *data)
{
        t_list  *p;

        p = *head;
        if (!p)
            *head = ft_create_elem(data);
        else
        {
            while (p->next)
                p = p->next;
            p->next = ft_create_elem(data);
        }
}

t_list  *ft_create_elem(void *data)
{
        t_list  *p;

        p = malloc(sizeof(t_list));
        if (!p)
            return (NULL);
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
