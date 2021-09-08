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

char    **ft_split(char *s, char *charset);
char    *fill_row(char *row, char *s, int index, int offset);
int     get_offset(char *s, int index, char *charset);
int     get_size(char *s, char *charser);
int     is_sep(char c, char *s);

// DRIVE

#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argc;
    int i = 0;
    char **grid = ft_split(argv[1], argv[2]);

    while (grid[i])
    {
        printf("%s \n", grid[i]);
        i++;
    }
    return (0);
}

//

char    **ft_split(char *s, char *charset)
{
    char    **grid;
    int     offset;
    int     size;
    int     i;
    int     j;

    size = get_size(s, charset);
    grid = malloc(sizeof(char *)*(size + 1));
    if (!grid)  return NULL;
    i = 0;
    j = 0;
    while (i < size)
    {
        while (s[j])
        {
            if (s[j] && !is_sep(s[j], charset))
            {
                offset = get_offset(s, j, charset);
                grid[i] = fill_row(grid[i], s, j, offset);
                j += offset;
                break;
            }
            j++;
        }
        i++;
    }
    if (!(grid[i] = malloc(sizeof(char))))  return NULL;
    grid[i] = 0;
    return grid;
}

char    *fill_row(char *row, char *s, int index, int offset)
{
    int     i;
    row = malloc(sizeof(char) * (offset + 1));
    if (!row)   return NULL;
    i = 0;
    while (i < offset)
    {
        row[i] = s[index + i];
        i++;
    }
    row[i] = 0;
    return row;
}

int     get_size(char *s, char *charset)
{
    int i, size, offset;

    if (!s) return 0;

    i = size = 0;
    while (s[i])
    {
        while (s[i] && is_sep(s[i], charset))
            i++;
        while (s[i] && !is_sep(s[i], charset))
        {
            size += 1;
            offset = get_offset(s, i, charset);
            i += offset;
            break;
        }
        if (!s[i])
            break;
        i++; 
    }
    return size;
}

int     get_offset(char *s, int index, char *charset)
{
    int     size = 0;
    int     i = index;
    while (s[i] && !is_sep(s[i], charset))
    {
        size++;
        i++;
    }
    return size;
}

int     is_sep(char c, char *s)
{
    int i = 0;
    while (s[i])
    {
        if (c == s[i])    return 1;
        i++;
    }
    return 0;
}
