/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:08:50 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:54:19 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_a.index;
	tmp = stacks->stack_a.tab[index];
	while (index < (stacks->stack_a.len - 1))
	{
		stacks->stack_a.tab[index] = stacks->stack_a.tab[index + 1];
		index++;
	}
	stacks->stack_a.tab[index] = tmp;
	if (i)
		write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_b.index;
	tmp = stacks->stack_b.tab[index];
	while (index < (stacks->stack_b.len - 1))
	{
		stacks->stack_b.tab[index] = stacks->stack_b.tab[index + 1];
		index++;
	}
	stacks->stack_b.tab[index] = tmp;
	if (i)
		write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_a.index;
	tmp = stacks->stack_a.tab[index];
	while (index < (stacks->stack_a.len - 1))
	{
		stacks->stack_a.tab[index] = stacks->stack_a.tab[index + 1];
		index++;
	}
	stacks->stack_a.tab[index] = tmp;
	index = stacks->stack_b.index;
	tmp = stacks->stack_b.tab[index];
	while (index < (stacks->stack_b.len - 1))
	{
		stacks->stack_b.tab[index] = stacks->stack_b.tab[index + 1];
		index++;
	}
	stacks->stack_b.tab[index] = tmp;
	if (i)
		write(1, "rr\n", 3);
}

void	rra(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_a.len - 1;
	tmp = stacks->stack_a.tab[index];
	while (index > stacks->stack_a.index)
	{
		stacks->stack_a.tab[index] = stacks->stack_a.tab[index - 1];
		index--;
	}
	stacks->stack_a.tab[index] = tmp;
	if (i)
		write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks, int i)
{
	int	tmp;
	int	index;

	index = stacks->stack_b.len - 1;
	tmp = stacks->stack_b.tab[index];
	while (index > stacks->stack_b.index)
	{
		stacks->stack_b.tab[index] = stacks->stack_b.tab[index - 1];
		index--;
	}
	stacks->stack_b.tab[index] = tmp;
	if (i)
		write(1, "rrb\n", 4);
}
