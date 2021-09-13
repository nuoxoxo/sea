/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

void    ft_list_push_front(t_list **list, void *data);
t_list  *ft_create_elem(void *data);

t_list  *ft_list_push_params(int ac, char **av)
{
        int         i;
        t_list      *p;

        if (ac < 2)
            return (NULL);
        p = ft_create_elem(av[1]);
        if (ac == 2)
            return (p);
        i = ac - 1;
        while (i > 1)
        {
            ft_list_push_front(&p, av[i]);
            i--;
        }
        return (p);
}

void    ft_list_push_front(t_list **list, void *data)
{
        t_list  *p;

        if (!list)
            *list = ft_create_elem(data);
        else
        {
            p = ft_create_elem(data);
            p->next = *list;
            *list = p;
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

/*

// DRIVE

#include    <stdio.h>

t_list  *ft_list_push_params(int argc, char **argv);
t_list  *ft_create_elem(void *d);
void    ft_list_push_front(t_list **p, void *d);

int     main(int argc, char **argv)
{
        int     i;
        t_list  *ptr;

        ptr = ft_list_push_params(argc, argv);
        i = 0;
        (void)argc;
        while (ptr)
        {
                printf("%c\n", *(char*)ptr->data);
                ptr = ptr->next;
        }
}

*/
