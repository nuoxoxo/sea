/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

void        swap_int_data(int *x, int *y);

t_list      *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int     size = 0;
    int     i;
    t_list  *list;
    t_list  *p;

    p = lst;
    if (!p) return NULL;
    
    while (p)
    {
        p = p->next;
        size++;
    }
    if (size < 2)   return lst;

    list = lst;
    i = 0;
    
    while (i < size - 1)
    {
        if (cmp(list[i].data, list[i + 1].data) == 0)
        {
            swap_int_data(&list[i].data, &list[i + 1].data);
            i = 0;
        }
        else    i++;
    }
    return lst;
}

void    swap_int_data(int *x, int *y)
{
        int     temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

/*

//  DRIVE

#include    <stdio.h>

t_list      *pp_int(int n, char **s);
t_list      *ce_int(int data);
void        put_int_list(t_list *lst);
int         compa(int a, int b);  

int     main(int argc, char **argv)
{
        t_list  *p;
        t_list  *sorted;

        p = pp_int(argc, argv);
        put_int_list(p);

        sorted = sort_list(p, compa);
        put_int_list(sorted);
}

int     compa(int a, int b)
{
        if (a > b)  return 0;
        return 1;
}

void    put_int_list(t_list *lst)
{
        t_list  *p;
        int i = 0;
        
        p = lst;
        printf("\nlist : \n");
        while (p)
        {
            printf("[%i] : %i\n", i, p->data);
            p = p->next;
            i++;
        }
        printf("\n");
}

t_list  *pp_int(int n, char **s)
{
        t_list  *head, *p;
        int     i = 1;

        if (n < 2)  return NULL;
        head = ce_int(atoi(s[i++]));

        p = head;
        while (i < n)
        {
            p->next = ce_int(atoi(s[i++]));
            p = p->next;
        }
        return  head;
}

t_list  *ce_int(int data)
{
        t_list  *p;

        p = malloc(sizeof(t_list));
        if (!p) return (NULL);
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
