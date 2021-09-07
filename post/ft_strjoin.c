/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strjoin(int size, char **strs, char *sep);
void    scat(char *des, char *src);
int     count_res_size(char **strs, char *sep);
int     len(char *s);

/// DRIVE

#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___:D___"));
}

//

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *res;
    int     i;

    if (!size)
    {
        res = malloc(sizeof(char));
        if (!res)
            return NULL;
        *res = 0;
        return res;
    }

    res = malloc(sizeof(char) * count_res_size(strs, sep));
    if (!res)
        return NULL;

    *res = 0;
    i = 0;
    while (strs[i])
    {
        scat(res, strs[i]);
        if (strs[i + 1])
            scat(res, sep);
        i++; 
    }
    return res;
}


void    scat(char *des, char *src)
{
    int i, j;
    i = j = 0;
    while (des[i])
        i++;
    while (src[j])
    {
        des[i + j] = src[j];
        j++;
    }
    des[i + j] = 0;
}

int count_res_size(char **strs, char *sep)
{
    int size_grid, size_sep, i;
    
    size_sep = len(sep);
    size_grid = 0;
    i = 0;
    
    while (strs[i])
    {
        size_grid += len(strs[i]);
        if (!strs[i + 1])
            size_grid += 1;
        else
            size_grid += size_sep;
        i++;
    }
    return size_grid;
}

int len(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}
