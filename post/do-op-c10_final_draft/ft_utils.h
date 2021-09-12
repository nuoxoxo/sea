/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef         FT_UTILS_H
#define         FT_UTILS_H

void            ops(int a, int b, void(*f)(int, int));
void            calc(int a, int b, char *c);
void            putlong(long n);
void            ft_mul(int a, int b);
void            ft_add(int a, int b);
void            ft_sub(int a, int b);
void            ft_div(int a, int b);
void            ft_mod(int a, int b);
//void          ft_usage(char *c);
void            ft_usage(int a, int b);
int             ft_strcmp(char *a, char *b);
int             ft_atoi(char *s);

// You have to define the type of t_opp 
// which corresponds to the s_opp structure 
// in order to compile the proj

typedef struct  s_opp
{
        char    *op;
        void    (*fn)(int, int);
}               t_opp;

#endif
