/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nd_others.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:39:45 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:48:21 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strdup(char *s)
{
	char	*re;
	int		len;
	int		i;

	len = slen(s);
	re = (char *)malloc(len + 1);
	if (!re)
		return (0);
	i = 0;
	while (s[i])
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

int	slen(char *c)
{
	int	l;

	if (!c)
		return (0);
	l = 0;
	while (c[l])
		l++;
	return (l);
}

char	*ft_strjoin(char *s0, char *s1)
{
	int		c0;
	int		c1;
	int		s0_len;
	int		s1_len;
	char	*re;

	if (!s0)
		s0 = ft_strdup("");
	s0_len = slen(s0);
	s1_len = slen(s1);
	re = (char *)malloc(s0_len + s1_len + 2);
	if (!re)
		return (0);
	c0 = -1;
	c1 = 0;
	while (++c0 < s0_len)
		re[c0] = s0[c0];
	re[c0++] = ' ';
	c1 = 0;
	while (c1 < s1_len)
		re[c0++] = s1[c1++];
	re[c0] = '\0';
	return (free(s0), re);
}

int	ft_abs_value(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

int	ft_larger_nb(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
