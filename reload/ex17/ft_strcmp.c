/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

// DRIVE

#include    <string.h>
#include    <stdio.h>

int     ft_strcmp(char *x, char *y);

int     main()
{
        char si[] = "";         char sj[] = "";
        char s1[] = "moon";     char s2[] = "child";
        char s3[] = "flower";   char s4[] = "";
	char s5[] = "";         char s6[] = "teapot";
        char s7[] = "Back";     char s8[] = "Pack";
        char s9[] = "Pop";      char s10[] = "PoP";
        printf("%d, %d\n", ft_strcmp(si, sj), strcmp(si, sj));
	printf("%d, %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
        printf("%d, %d\n", ft_strcmp(s3, s4), strcmp(s3, s4));
	printf("%d, %d\n", ft_strcmp(s5, s6), strcmp(s5, s6));
	printf("%d, %d\n", ft_strcmp(s7, s8), strcmp(s7, s8));
	printf("%d, %d\n", ft_strcmp(s9, s10), strcmp(s9, s10));
}

*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
