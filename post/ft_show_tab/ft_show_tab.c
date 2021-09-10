/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:04:35 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/24 19:15:10 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>

struct	s_stock_str *ft_strs_to_tab(int ac, char **av);
void    ft_show_tab(struct s_stock_str *p);
void	put_pos_num(int n);

// DRIVE

int     main(int ac, char **av)
{
	t_stock_str *stock = ft_strs_to_tab(ac, av);
        ft_show_tab(stock);
        free(stock);
	return 0;
}

//

void	ft_show_tab(struct s_stock_str *par)
{
        while   (par->str)
        {
            write(1, par->str, par->size);
	    write(1, "\n", 1);
            put_pos_num(par->size);
	    write(1, "\n", 1);
	    write(1, par->copy, par->size);
	    write(1, "\n", 1);
            par++;
        }
}

void    put_pos_num(int n)
{
        char    c;
        
        if (n < 10 && n >= 0)
        {
                c = n + '0';
                write(1, &c, 1);
        }
        else
        {
                put_pos_num(n / 10);
                c = n % 10 + '0';
                write(1, &c, 1);
        }
}
