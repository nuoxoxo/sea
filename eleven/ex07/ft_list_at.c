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

/*

// DRIVE

#include    <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        (void)  argc;
        
        t_list  *head;
        t_list  *p;
        int     i;

        if (!(p = pp(argc, argv)))  return 0;
        
        head = p;
        i = 0;
        
        printf("\nFull list : \n");
        
        while (p)
        {
            printf("[%i] : %c\n", i, *(char*)p->data);
            p = p->next;
            i++;
        }

        i = 4;
        printf("\nData at %i : %c",i,*(char*)ft_list_at(head,i)->data);
        
        i = 2;
        printf("\nData at %i : %c\n\n",i,*(char*)ft_list_at(head,i)->data);
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
        if (!p) return (NULL);
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
