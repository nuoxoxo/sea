/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainf ck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int     arr[4096];
    int     loop;
    int     *p;
    int     i;
    char    *s;

    if (ac != 2)
        return (-1);
    
    s = av[1];
    p = arr;
    i = 0;
    while (s[i])
    {
        if (s[i] == '+')
            (*p)++;
        else if (s[i] == '-')
            (*p)--;
        else if (s[i] == '>')
            p++;
        else if (s[i] == '<')
            p--;
        else if (s[i] == '[' && *p == 0)    // '[' go to the matching ']'
                                            // if the pointed byte is 0 (while start)
        {
            loop = 1;
            while (loop)
            {
                i++;
                if (s[i] == '[')
                    loop++;
                else if (s[i] == ']')
                    loop--;
            }
        }
        else if (s[i] == ']' && *p != 0)    // ']' go to the matching '['
                                            // if the pointed byte is not 0 (while end)
        {
            loop = 1;
            while (loop)
            {
                i--;
                if (s[i] == ']')
                    loop++;
                else if (s[i] == '[')
                    loop--;
            }
        }
        else if (s[i] == '.')
            write(1, p, 1);
        i++;
    }
}
