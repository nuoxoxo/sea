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

t_list  *ft_create_elem(void *data);

t_list  *ft_list_push_params(int ac, char **av)
{
        t_list      *head;
        t_list      *p;
        int         i;

        i = 1;
        if (ac < 2)
            return (NULL);
        head = ft_create_elem(av[i++]);
        p = head;
        while (i < ac)
        {
            p->next = ft_create_elem(av[i++]);
            p = p->next;
        }
        return (head);
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

int     main(int argc, char **argv)
{
        (void)  argc;
        t_list  *p;

        p = ft_list_push_params(argc, argv);
        while (p)
        {
                printf("%c\n", *(char*)p->data);
                p = p->next;
        }
}

*/