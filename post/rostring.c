/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void    copy_substring(char *d, char *s, int start, int end);
void    rostring(char **grid, int size, char *s);
void    grid_dump(char **grid);
int     len_ahead(char *s, int i);
int     len_key(char *s);
int     issp(char c);
int     len(char *s);

int main(int argc, char **argv)
{
    char    **grid;
    int     size;
    
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    if (!(size = len_key(argv[1]))) return 0;
    if (!(grid = malloc(sizeof(char *) * (size + 1)))) return 0;
    rostring(grid, size, argv[1]);
    grid_dump(grid);
}

void    grid_dump(char **grid)
{
        int i = 0;
        int j;

        while (grid[i])
        {
            j = 0;
            while (grid[i][j])
            {
                write(1, &grid[i][j], 1);
                j++;
            }
            if (grid[i + 1])    write(1, " ", 1);
            i++;
        }
}

void    rostring(char **grid, int size, char *s)
{
        int offset, i;

        grid[size--] = 0;
        i = offset = 0;
        while (issp(s[i]))  i++;
        offset = len_ahead(s, i);
        grid[size] = malloc(sizeof(char) * (offset + 1));
        if (!grid[size])    return ;
        copy_substring(grid[size], s, i, offset + i);
        i += offset;
        size = 0;
        while (i < len(s))
        {
            if (issp(s[i]))
            {
                while (issp(s[i]) && i < len(s))  i++;
            }
            else
            {
                offset = len_ahead(s, i);
                grid[size] = malloc(sizeof(char) * (offset + 1));
                if (!grid[size])    return;
                copy_substring(grid[size], s, i, offset + i);
                i += offset;
                size += 1;
            }
        }
}

void    copy_substring(char *d, char *s, int start, int end)
{
        int i = 0;
        while (start < end) d[i++] = s[start++];
        d[i] = 0;
}

int len_ahead(char *s, int i)
{
    int     size = 0;
    
    if (!issp(s[i]))
    {
        while (s[i] && !issp(s[i++]))   size++;
    }
    else
    {
        while (s[i] && issp(s[i++]))    size++;
    }
    return size;
}

int len_key(char *s)
{
    int i, size, offset;
    
    size = i = 0;
    while (i < len(s))
    {
        offset = len_ahead(s, i);
        if (!issp(s[i]))    size++;
        i += offset;
    }
    return size;
}

int issp(char c)
{
    if (c == ' ' || (c < 14 && c > 8))  return 1;
    return 0;
}

int len(char *s)
{
    int i = 0;
    while (s[i])    i++;
    return  i;
}
