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


// DRIVE

#include    <stdio.h>

t_list  *pp(int argc, char **argv);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        (void)  argc;
        
        t_list  *p;
        int     i;

        if (!(p = pp(argc, argv)))  return 0;


        printf("\ndata of the last item : %c\n", *(char*)ft_list_last(p)->data);
        printf("\nthe full list : \n");
        
        i = 0;
        while (p)
        {
            printf("[%i] : %c\n", i, *(char*)p->data);
            p = p->next;
            i++;
        }

        printf("\n");
}

t_list  *pp(int ac, char **av)
{
        t_list  *head, *p;
        int     i = 1;
        
        if (ac < 2) return NULL;
        head = ce(av[i++]);
        p = head;
        while   (i < ac)
        {
                p->next = ce(av[i++]);
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
        return  p;
}
