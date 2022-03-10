/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:04:29 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:51:05 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_stacks *stacks)
{
	int	i;

	if (stacks->stack_a.index)
	{
		write(2, "KO\n", slen("KO\n"));
		exit(0);
	}
	i = 0;
	while (i < stacks->stack_a.len - 1)
	{
		if (stacks->stack_a.tab[i] > stacks->stack_a.tab[i + 1])
		{
			write(2, "KO\n", slen("KO\n"));
			exit(0);
		}
		i++;
	}
	write(2, "OK\n", slen("OK\n"));
	exit(0);
}
