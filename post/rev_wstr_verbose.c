/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
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
void    grid_dump(char **grid);
int     count_size_forward(char *s, int index);
int     iswsp(char c);
int     len(char *s);

int main(int argc, char **argv)
{
    char    **grid;
    int     size_ahead = 0;
    int     size_grid = 0;
    int     i = 0;
    
    if (argc != 2 || !argv[1]) 
    {
        write(1, "\n", 1);
        return 0;
    }
    while (argv[1][i++])
    {
        if (iswsp(argv[1][i]))  size_grid++;
    }
    if (!size_grid)
    {
        write(1, "\n", 1);
        return 0;
    }
    if (!(grid = malloc(sizeof(char*)*(size_grid + 1)))) return 0;
    grid[size_grid--] = 0;
    i = 0;
    while (i < len(argv[1]))
    {
        size_ahead = count_size_forward(argv[1], i);
        if (!(grid[size_grid] = malloc(sizeof(char) * (size_ahead + 1))))
                return 0;
        copy_substring(grid[size_grid], argv[1], i, size_ahead + i);
        i += size_ahead + 1;
        size_grid -= 1;
    }
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

void    copy_substring(char *d, char *s, int start, int end)
{
        int i = 0;
            while (start < end) d[i++] = s[start++];
        d[i] = 0;
}

int     count_size_forward(char *s, int index)
{
        int i = index;
        int size = 0;
        while (s[i] && !iswsp(s[i++]))  size++;
        return size;
}

int     iswsp(char c)
{
        if (!c || c == ' ' || (c < 14 && c > 8))    return 1;
        return 0;

}

int     len(char *s)
{
        int i = 0;
        while (s[i])    i++;
        return i;
}
