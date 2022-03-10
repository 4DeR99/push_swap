/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:51:26 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 14:56:13 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	utils1(t_stacks *stacks, t_moves moves)
{
	while (moves.moves_a > 0 && moves.moves_b > 0)
	{
		rr(stacks, 1);
		moves.moves_a--;
		moves.moves_b--;
	}
	while (moves.moves_a)
	{
		ra(stacks, 1);
		moves.moves_a--;
	}
	while (moves.moves_b)
	{
		rb(stacks, 1);
		moves.moves_b--;
	}
}

static void	utils2(t_stacks *stacks, t_moves moves)
{
	while (moves.moves_a < 0 && moves.moves_b < 0)
	{
		rrr(stacks, 1);
		moves.moves_a++;
		moves.moves_b++;
	}
	while (moves.moves_a)
	{
		rra(stacks, 1);
		moves.moves_a++;
	}
	while (moves.moves_b)
	{
		rrb(stacks, 1);
		moves.moves_b++;
	}
}

static void	utils3(t_stacks *stacks, t_moves moves)
{
	while (moves.moves_a)
	{
		ra(stacks, 1);
		moves.moves_a--;
	}
	while (moves.moves_b)
	{
		rrb(stacks, 1);
		moves.moves_b++;
	}
}

static void	utils4(t_stacks *stacks, t_moves moves)
{
	while (moves.moves_a)
	{
		rra(stacks, 1);
		moves.moves_a++;
	}
	while (moves.moves_b)
	{
		rb(stacks, 1);
		moves.moves_b--;
	}
}

void	push_a(t_stacks *stacks, t_moves moves)
{
	if (moves.moves_a >= 0 && moves.moves_b >= 0)
		utils1(stacks, moves);
	if (moves.moves_a <= 0 && moves.moves_b <= 0)
		utils2(stacks, moves);
	if (moves.moves_a > 0 && moves.moves_b < 0)
		utils3(stacks, moves);
	if (moves.moves_a < 0 && moves.moves_b > 0)
		utils4(stacks, moves);
	pa(stacks, 1);
}
