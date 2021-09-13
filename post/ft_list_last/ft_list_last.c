/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

t_list  *ft_list_last(t_list *begin_list)
{
        t_list      *end;

        end = begin_list;
        if (!end)
            return (NULL);
        while (end->next)
            end = end->next;
        return (end);
}

/*

// DRIVE

#include    <stdio.h>

void    ft_list_push_front(t_list **head, void *data);
void    ft_list_push_back(t_list **head, void *data);
t_list  *ft_create_elem(void *d);

int     main(int argc, char **argv)
{
        (void)          argc;
        
        char            data1 = *argv[1];
        unsigned int    data2 = atoi(argv[2]);
        short           data3 = atoi(argv[3]); 
        long            data4 = atoi(argv[4]);
        int             data5 = atoi(argv[5]);
        t_list          *p;

        p = ft_create_elem(&data1);
        ft_list_push_front(&p, &data2);
        ft_list_push_back(&p, &data3);
        ft_list_push_front(&p, &data4);
        ft_list_push_back(&p, &data5);
        
        printf("\ndata of the last item : %i\n\n", *(int*)ft_list_last(p)->data);
        
        printf("the full list\n[0] : %li\n", *(long*)p->data);
        printf("[1] : %u\n", *(unsigned int*)p->next->data);
        printf("[2] : %c\n", *(char*)p->next->next->data);
        printf("[3] : %i\n", *(short*)p->next->next->next->data);
        printf("[4] : %i\n\n", *(int*)p->next->next->next->next->data);
}

void    ft_list_push_front(t_list **head, void *data)
{
        t_list  *p;

        if (!head)
            *head = ft_create_elem(data);
        else
        {
            p = ft_create_elem(data);
            p->next = *head;
            *head = p;
        }
}

void    ft_list_push_back(t_list **head, void *data)
{
        t_list  *p;

        p = *head;
        if (!head)
            *head = ft_create_elem(&data);
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
