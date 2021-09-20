/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
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

        if (ac < 2)
            return (NULL);
        i = ac - 1;
        head = ft_create_elem(av[i--]);
        p = head;
        while (i > 0)
        {
            p->next = ft_create_elem(av[i--]);
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
        t_list  *p;

        p = ft_list_push_params(argc, argv);
        printf("\nTotally inverted : \n\n");
        while (p)
        {
                printf("%s\n", (char*)p->data);
                p = p->next;
                if (!p) printf("\n");
        }
}

*/
