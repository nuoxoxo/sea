/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:33:45 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/24 16:58:07 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_index_in_base(char c, char *base);
int     ft_atoi_base(char *str, char *base);
int	base_is_valid(char *base);
int     len(char *s);

// Drive

#include <stdio.h>

int	main()
{
	printf("42 : %d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("42 : %d\n", ft_atoi_base("-2a", "0123456789abcdef"));
	printf("1390 selon jalu baseconverter:%d\n", ft_atoi_base("naai", "ponytail"));
	printf("-42 : %d\n", ft_atoi_base("   --------+-2a", "0123456789abcdef"));
	printf("0 : %d\n", ft_atoi_base("   -+-2a", "012345678\nabcdef"));
	printf("0 : %d\n", ft_atoi_base("   --------+- 2a", "0123456789abcdef"));
	printf("0 : %d\n", ft_atoi_base("   --------+-z", "0123456789abcdef"));
	printf("0 : %d\n", ft_atoi_base("   --------+-2a", ""));
	printf("0 : %d\n", ft_atoi_base("   --------+-2a", "0"));
	printf("0 : %d\n", ft_atoi_base("   --------+-2a", "+-0"));
	printf("0 : %d\n", ft_atoi_base("   --------+-2a", "\t01"));
	printf("512 %d\n", ft_atoi_base("1000000000", "01"));
	printf("19 : %d\n", ft_atoi_base("91", "0923456781"));
	printf("-42 : %d\n", ft_atoi_base(" ++---101010", "01"));
}

//

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	tt;
	int	i;

	if (base_is_valid(base) == 0)
		return (0);
	sign = 1;
	tt = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (find_index_in_base(str[i], base) != -1)
	{
		tt = tt * len(base) + find_index_in_base(str[i], base);
		i++;
	}
	return (sign * tt);
}

int	find_index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


int	base_is_valid(char *base)
{
	int	i;
	int	j;

	if (len(base) < 2)
		return (0);
	i = 0;
	while (i < len(base))
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] < 14 && base[i] > 8))
			return (0);
		i++;
	}
	i = 0;
	while (i < len(base) - 1)
	{
		j = i + 1;
		while (j < len(base))
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
