/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
        t_list          *p;
        unsigned int    i;

        p = begin_list;
        if (!p)
            return (NULL);
        i = 1;
        while (p)
        {
            if (i == nbr)
                return (p);
            p = p->next;
            i++;
        }
        return (NULL);
}



// DRIVE

#include    <stdio.h>

void    ft_list_push(t_list **head, void *data);
t_list  *ft_create_elem(void *d);

int     main(int argc, char **argv)
{
        (void)      argc;

        char        data1 = *argv[1];
        char        data2 = *argv[2];
        char        data3 = *argv[3]; 
        char        data4 = *argv[4];
        char        data5 = *argv[5];
        t_list      *test;
        t_list      *p;
        t_list      *c;
        int         nbr;
        int         i;

        ft_list_push(p, &data1);
        ft_list_push(&p, &data2);
        ft_list_push(&p, &data3);
        ft_list_push(&p, &data4);
        ft_list_push(&p, &data5);
        printf("\n");

        i = 1;
        c = p;
        while (c)
        {
            printf("[%i] : %c\n", i, *(char*)c->data);
            c = c->next;
            i++;
        }

        nbr = 4;
        test = ft_list_at(p, nbr);
        printf("\ntest data at [%i] : %c\n", nbr, *(char*)test->data);
        
        nbr = 2;
        test = ft_list_at(p, nbr);
        printf("\ntest data at [%i] : %c\n\n", nbr, *(char*)test->data);
}

void    ft_list_push(t_list **head, void *data)
{
        t_list  *p;

        p = *head;
        if (! p)
            p = ft_create_elem(data);
        else
        {
            while ((p)->next)
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

