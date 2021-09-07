/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:33:45 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/19 12:11:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     is_num(char c);
int     is_wsp(char c);
int     ft_atoi(char *str);

// DRIVE

#include <stdio.h>

int main(){
        printf("-42:%d\n", ft_atoi(" --+-042a:f545"));
	printf("42:%d\n", ft_atoi("  \n  42t4457"));
	printf("0:%d\n", ft_atoi("\0 1337"));
	printf("0:%d\n", ft_atoi("-0"));
	printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
	printf("-1325632167:%d\n", ft_atoi("-1325632167"));
	printf("-100:%d\n", ft_atoi("-100"));
	printf("min:%d\n", ft_atoi("\t---+2147483648"));
	printf("max:%d\n", ft_atoi("\v2147483647"));
}

//

int	ft_atoi(char *str)
{
	int	sign;
	int	tt;
	int	i;

	sign = 1;
	tt = 0;
	i = 0;
	while (is_wsp(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_num(str[i]) == 1)
	{
		tt = tt * 10 + str[i] - '0';
		i++;
	}
	return (sign * tt);
}

int	is_num(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	is_wsp(char c)
{
	if (c == ' ' || (c < 14 && c > 8))
		return (1);
	return (0);
}
