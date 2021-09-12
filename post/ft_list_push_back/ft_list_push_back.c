/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdlib.h>
#include    "ft_list.h"

t_list  *ft_create_elem(void *d);

void    ft_list_push_back(t_list **begin_list, void *data)
{
        t_list  *thing;

        thing = *begin_list;
        if (!thing)
            *begin_list = ft_create_elem(data);
        else
        {
            while (thing->next) 
                thing = thing->next;
            thing->next = ft_create_elem(data);
        }
}

t_list  *ft_create_elem(void *data)
{
        t_list  *thing;

        thing = malloc(sizeof(t_list));
        if (!thing)
            return (NULL);
        thing->data = data;
        thing->next = NULL;
        return (thing);
}

// DRIVE

#include    <stdlib.h>
#include    <stdio.h>

int     main(int argc, char **argv)
{
        (void)  argc;
        char    data1 = *argv[1];
        int     data2 = atoi(argv[2]);
        t_list  *thing;

        ft_list_push_back(&thing, &data1);
        ft_list_push_back(&thing, &data2);
        printf("%c\n%i\n", *(char *)thing->data, *(int*)thing->next->data);
}
