/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
        t_list      *head;

        head = *begin_list1;
        while (head->next)    head = head->next;
        head->next = begin_list2;
}

/*

// DRIVE

#include    <stdio.h>

t_list      *pp(int n, char **s);
t_list      *ce(void *d);
void        ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int     main(int argc, char **argv)
{
        t_list      *p;
        t_list      *list_1;
        t_list      *list_2, *list_3;
        
        list_1 = pp(argc, argv);
        list_2 = ce((char *)"hello world");
        list_3 = ce((char *)"good music");
        list_2->next = list_3;
        
        printf("\nHere is list 1 : \n");
        p = list_1;
        while (p)
        {
            printf("%s\n", (char*)p->data);
            p = p->next;
        }        
        
        printf("\nHere s list 2 : \n");
        p = list_2;
        while (p)
        {
            printf("%s\n", (char*)p->data);
            p = p->next;
        }
        ft_list_merge(&list_1, list_2);

        printf("\nLists 1 & 2 merged : \n");
        p = list_1;
        while (p)
        {
            printf("%s\n", (char*)p->data);
            p = p->next;
        }
}

t_list  *pp(int n, char **s)
{
        t_list  *head, *p;
        int     i = 1;

        if (n < 2)  return NULL;
        head = ce(s[i++]);
        p = head;
        while (i < n)
        {
            p->next = ce(s[i++]);
            p = p->next;
        }
        return  head;
}

t_list  *ce(void *data)
{
        t_list  *p;

        p = malloc(sizeof(t_list));
        if (!p) return NULL;
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
