/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:04:35 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/24 19:15:10 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char    *ft_strdup(char *s);
int     ft_strlen(char *s);

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *ptr;
	int	    i;

	ptr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
                ptr[i].size = ft_strlen(av[i]);
                ptr[i].str  = av[i];
                ptr[i].copy = ft_strdup(av[i]);
                i++;
	}
	ptr[i].str = 0;
	return (ptr);
}

char	*ft_strdup(char *src)
{
	char	*des;
	char	*ptr;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	des = malloc(sizeof(char) * (len + 1));
	if (!des)
		return (NULL);
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = '\0';
	return (ptr);
}

int     ft_strlen(char *s)
{
        int i;

        i = 0;
        while (s[i])
            i++;
        return (i);
}
