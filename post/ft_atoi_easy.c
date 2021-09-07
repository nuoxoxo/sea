/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_easy.c                                     :+:      :+:    :+:   */
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
#include <stdlib.h>

int main(){
        printf("-42 : %d \n", ft_atoi("     -42aE^&tk54Mf9"));
        printf("-42 : %d \n", atoi("    -42aE^&tk54Mf9"));
        printf("42 : %d \n", ft_atoi("     +42aE^&tk54Mf9"));
        printf("42 : %d \n\n", atoi("    +42aE^&tk54Mf9"));
        
        printf("-42 : %d \n", ft_atoi("     -0042aE^&tk54Mf9"));
        printf("-42 : %d \n", atoi("    -0042aE^&tk54Mf9"));
        printf("42 : %d \n", ft_atoi("     +0042aE^&tk54Mf9"));
        printf("42 : %d \n\n", atoi("    +0042aE^&tk54Mf9"));
        
        printf("0 : %d \n", ft_atoi("     --042aE^&tk54Mf9"));
        printf("0 : %d \n", atoi("    --042aE^&tk54Mf9"));
        printf("0 : %d \n", ft_atoi("     ++042aE^&tk54Mf9"));
        printf("0 : %d \n\n", atoi("    ++042aE^&tk54Mf9"));
	
        printf("0 : %d \n", ft_atoi(" \v\t- 1 0 2 4"));
	printf("0 : %d \n", atoi(" \v\t- 1 0 2 4"));
        printf("-1 : %d \n", ft_atoi(" \v\t-1 0 2 4"));
	printf("-1 : %d \n\n", atoi(" \v\t-1 0 2 4"));
	 
	printf("min : %d \n", ft_atoi(" \f\n\r\t\v -2147483648"));
	printf("min : %d \n", atoi(" \f\n\r\t\v -2147483648"));
        printf("max : %d \n", ft_atoi("\v2147483647"));
        printf("max : %d \n\n", atoi("\v2147483647"));

        printf("0 (-0) : %d \n", ft_atoi("-0"));
        printf("0 (-0) : %d \n", atoi("-0"));
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
	if (str[i] == '-' || str[i] == '+')
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
