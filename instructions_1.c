/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:18:49 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:59:55 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stacks *stacks, int i)
{
	stacks->stack_b.tab[stacks->stack_b.index - 1]
		= stacks->stack_a.tab[stacks->stack_a.index];
	stacks->stack_a.index++;
	stacks->stack_b.index--;
	if (i)
		write(1, "pb\n", 3);
}

void	pa(t_stacks *stacks, int i)
{
	stacks->stack_a.tab[stacks->stack_a.index - 1]
		= stacks->stack_b.tab[stacks->stack_b.index];
	stacks->stack_a.index--;
	stacks->stack_b.index++;
	if (i)
		write(1, "pa\n", 3);
}

void	sa(t_stacks *stacks, int i)
{
	int	tmp;

	tmp = stacks->stack_a.tab[stacks->stack_a.index];
	stacks->stack_a.tab[stacks->stack_a.index]
		= stacks->stack_a.tab[stacks->stack_a.index + 1];
	stacks->stack_a.tab[stacks->stack_a.index + 1] = tmp;
	if (i)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks, int i)
{
	int	tmp;

	tmp = stacks->stack_b.tab[stacks->stack_b.index];
	stacks->stack_b.tab[stacks->stack_b.index]
		= stacks->stack_b.tab[stacks->stack_b.index + 1];
	stacks->stack_b.tab[stacks->stack_b.index + 1] = tmp;
	if (i)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks, int i)
{
	int	tmp;

	tmp = stacks->stack_a.tab[stacks->stack_a.index];
	stacks->stack_a.tab[stacks->stack_a.index]
		= stacks->stack_a.tab[stacks->stack_a.index + 1];
	stacks->stack_a.tab[stacks->stack_a.index + 1] = tmp;
	tmp = stacks->stack_b.tab[stacks->stack_b.index];
	stacks->stack_b.tab[stacks->stack_b.index]
		= stacks->stack_b.tab[stacks->stack_b.index + 1];
	stacks->stack_b.tab[stacks->stack_b.index + 1] = tmp;
	if (i)
		write(1, "ss\n", 3);
}
