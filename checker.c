/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:36:26 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/09 18:40:31 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_instruction(char *ins)
{
	if (ins[0] == 'p' && (ins[1] == 'a' || ins[1] == 'b') && ins[2] == '\n')
		return ;
	if (ins[0] == 's' && (ins[1] == 'a' || ins[1] == 'b' || ins[1] == 's')
		&& ins[2] == '\n')
		return ;
	if (ins[0] == 'r' && (ins[1] == 'a' || ins[1] == 'b' || ins[1] == 'r')
		&& ins[2] == '\n')
		return ;
	if (ins[0] == 'r' && ins[1] == 'r'
		&& (ins[2] == 'a' || ins[2] == 'b' || ins[2] == 'r') && ins[3] == '\n')
		return ;
	write(2, "Error\n", slen("Error\n"));
	exit(0);
}

static void	util(char *ins, t_stacks *stacks)
{
	if (ins[0] == 'r' && (ins[1] == 'a' || ins[1] == 'b' || ins[1] == 'r')
		&& ins[2] == '\n')
	{
		if (ins[1] == 'a')
			ra(stacks, 0);
		if (ins[1] == 'b')
			rb(stacks, 0);
		if (ins[1] == 'r')
			rr(stacks, 0);
	}
	if (ins[0] == 'r' && ins[1] == 'r'
		&& (ins[2] == 'a' || ins[2] == 'b' || ins[2] == 'r') && ins[3] == '\n')
	{
		if (ins[2] == 'a')
			rra(stacks, 0);
		if (ins[2] == 'b')
			rrb(stacks, 0);
		if (ins[2] == 'r')
			rrr(stacks, 0);
	}
}

static void	do_instruction(char *ins, t_stacks *stacks)
{
	if (ins[0] == 'p' && (ins[1] == 'a' || ins[1] == 'b') && ins[2] == '\n')
	{
		if (ins[1] == 'a')
			pa(stacks, 0);
		if (ins[1] == 'b')
			pb(stacks, 0);
	}
	if (ins[0] == 's' && (ins[1] == 'a' || ins[1] == 'b' || ins[1] == 's')
		&& ins[2] == '\n')
	{
		if (ins[1] == 'a')
			sa(stacks, 0);
		if (ins[1] == 'b')
			sb(stacks, 0);
		if (ins[1] == 's')
			ss(stacks, 0);
	}
	util(ins, stacks);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*instruction;

	if (ac == 1)
	{
		write(2, "------------PUSH_SWAP-----------\n",
			slen("------------PUSH_SWAP-----------\n"));
		write(2, "HOW TO : ./push_swap + -NUMBERS-\n",
			slen("HOW TO : ./push_swap + -NUMBERS-\n"));
		exit(0);
	}
	configure(&stacks, av);
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		check_instruction(instruction);
		do_instruction(instruction, &stacks);
		free(instruction);
		instruction = get_next_line(0);
	}
	check_sort(&stacks);
}
