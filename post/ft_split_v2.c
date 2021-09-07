/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    **ft_split(char *s);
char    *fill_row(char *row, char *s, int index, int offset);
int     get_full_size(char *s);
int     get_next_size(char *s, int index);
int     is_wsp(char c);

// DRIVE

#include <stdio.h>

int     main(int argc, char **argv)
{
    (void)argc;
    int i = 0;
    char **grid = ft_split(argv[1]);
    
    while (grid[i])
    {
        printf("%s \n", grid[i]);
        i++;
    }
    return (0);
}

//

char    **ft_split(char *s)
{
    char    **grid;
    int     offset;
    int     size;
    int     i;
    int     j;

    size = get_full_size(s);
    if (!(grid = malloc(sizeof(char *)*(size + 1))))
        return NULL;
    
    i = 0;
    j = 0;
    while (i < size)
    {
        while (s[j])
        {
            if (s[j] && !is_wsp(s[j]))
            {
                offset = get_next_size(s, j);
                grid[i] = fill_row(grid[i], s, j, offset);
                j += offset;
                break;
            }
            j++;
        }
        i++;
    }
    if (!(grid[i] = malloc(sizeof(char))))
        return NULL;
    grid[i] = 0;
    return grid;
}

char    *fill_row(char *row, char *s, int index, int offset)
{
    int     i;
    if (!(row = malloc(sizeof(char) * (offset + 1))))
        return NULL;
    i = 0;
    while (i < offset)
    {
        row[i] = s[index + i];
        i++;
    }
    row[i] = 0;
    return row;
}


int     get_full_size(char *s)
{
    int     i;
    int     size;
    int     offset;

    if (!s) return 0;
    
    i = 0;
    size = 0;
    while (s[i])
    { 
        while (s[i] && is_wsp(s[i]))
            i++;
        while (s[i] && !is_wsp(s[i]))
        {
            size += 1;
            offset = get_next_size(s, i);
            i += offset;
            break ;
        }
        if (!s[i])
            break ;
        i++;
    }
    return size;
}

int     get_next_size(char *s, int index)
{
    int     size;
    int     i;

    size = 0;
    i = index;
    while (s[i] && !is_wsp(s[i]))
    {
        size++;
        i++;
    }
    return size;
}

int     is_wsp(char c)
{
    if (c == ' ' || (c < 14 && c > 8))
        return 1;
    return 0;
}
