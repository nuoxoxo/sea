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

char    **grid_copy(int size, char *s);
void    grid_dump(char **grid);
void    copy_substring(char *d, char *s, int start, int end);
int     count_size_forward(char *s, int index);
int     iswsp(char c);
int     len(char *s);

int     main(int argc, char **argv)
{
        char    **grid;
        int     size = 0;
        int     i = 0;

        if (argc != 2 || !argv[1]) 
        {
            write(1, "\n", 1);
            return 0;
        }
        while (argv[1][i++])
        {
            if (iswsp(argv[1][i]))  size++;
        }
        if (!size)
        {
            write(1, "\n", 1);
            return 0;
        }
        grid = grid_copy(size, argv[1]);
        grid_dump(grid);
}

char    **grid_copy(int size, char *s)
{
        char    **grid;
        int     size_ahead;
        int     i;
    
        if (!(grid = malloc(sizeof(char*)*(size + 1)))) return 0;
        grid[size--] = 0;
        i = 0;
        while (i < len(s))
        {
            size_ahead = count_size_forward(s, i);
            grid[size] = malloc(sizeof(char) * (size_ahead + 1));
            if (!grid[size])    return 0;
            copy_substring(grid[size], s, i, size_ahead + i);
            i += size_ahead + 1;
            size -= 1;
        }
        return grid;
}

void    copy_substring(char *d, char *s, int start, int end)
{
        int i = 0;
        while (start < end) d[i++] = s[start++];
        d[i] = 0;
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

int     count_size_forward(char *s, int i)
{
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
