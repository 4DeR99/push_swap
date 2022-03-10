/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:29:53 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 19:08:45 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_double_int	starting_point(int *lis1, int len)
{
	t_double_int	info;
	int				i;

	i = 0;
	info.i = 0;
	info.s_point_v = lis1[0];
	while (i < len)
	{
		if (lis1[i] > info.s_point_v)
		{
			info.s_point_v = lis1[i];
			info.i = i;
		}
		i++;
	}
	return (info);
}

static t_tab	get_lis_util1(int *tab, t_double_int info, int len)
{
	t_tab	re;
	int		i;
	int		tmp;

	i = 0;
	re.tab = (int *)malloc(sizeof(int) * info.s_point_v);
	tmp = info.i;
	re.len = info.s_point_v;
	re.tab[i] = tab[info.i++];
	if (info.i == len)
		info.i = 0;
	while (info.i != tmp)
	{
		if (re.tab[i] < tab[info.i])
		{
			i++;
			re.tab[i] = tab[info.i];
		}
		info.i++;
		if (info.i == len)
			info.i = 0;
	}
	return (re);
}

static t_tab	get_lis_util2(int *tab, t_double_int info, int len)
{
	t_tab	re;
	int		i;
	int		tmp;

	re.tab = (int *)malloc(sizeof(int) * info.s_point_v);
	i = info.s_point_v - 1;
	re.len = info.s_point_v;
	tmp = info.i;
	re.tab[i] = tab[info.i--];
	if (info.i == -1)
		info.i = len - 1;
	while (info.i != tmp)
	{
		if (re.tab[i] > tab[info.i])
		{
			i--;
			re.tab[i] = tab[info.i];
		}
		info.i--;
		if (info.i == -1)
			info.i = len - 1;
	}
	return (re);
}

t_tab	get_lis(t_lis lis_t, int *tab, int len)
{
	t_tab			re;
	t_double_int	info_increasing;
	t_double_int	info_decreasing;

	info_increasing = starting_point(lis_t.lis1, len);
	info_decreasing = starting_point(lis_t.lis2, len);
	if (info_increasing.s_point_v >= info_decreasing.s_point_v)
		re = get_lis_util1(tab, info_increasing, len);
	else
		re = get_lis_util2(tab, info_decreasing, len);
	free(lis_t.lis1);
	free(lis_t.lis2);
	return (re);
}
