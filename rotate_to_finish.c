/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_finish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:42:30 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 15:21:15 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stacks *stacks)
{
	int	pos;
	int	i;
	int	min;

	pos = 0;
	i = 0;
	min = stacks->stack_a.tab[i];
	while (i < stacks->stack_a.len)
	{
		if (min > stacks->stack_a.tab[i])
		{
			min = stacks->stack_a.tab[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	rotate_to_finish(t_stacks *stacks)
{
	int	pos;

	pos = get_min_pos(stacks);
	if (pos < (stacks->stack_a.len / 2 + 1))
	{
		while (pos > 0)
		{
			ra(stacks, 1);
			pos--;
		}
	}
	else
	{
		while (pos < stacks->stack_a.len)
		{
			rra(stacks, 1);
			pos++;
		}
	}
}
