/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moulmado <moulmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:30:22 by moulmado          #+#    #+#             */
/*   Updated: 2022/03/10 08:27:48 by moulmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int	len;
	int	index;
	int	*tab;
}				t_list;
typedef struct s_lis
{
	int	*lis1;
	int	*lis2;
}				t_lis;
typedef struct s_stacks
{
	t_list	stack_a;
	t_list	stack_b;
	int		m;
}				t_stacks;
typedef struct s_double_int
{
	int	i;
	int	s_point_v;
}				t_double_int;
typedef struct s_moves
{
	int	moves_a;
	int	moves_b;
}				t_moves;
typedef struct s_tab
{
	int	*tab;
	int	len;
}				t_tab;
void	configure(t_stacks *stacks, char **av);
void	sort_three(t_stacks *stacks);
char	**join_nd_split(char **av, int *len);
char	*ft_strjoin(char *s0, char *s1);
char	*ft_strjoin_gnl(char *s0, char *s1);
char	**ft_split(char *s, char c);
void	check_sort(t_stacks *stacks);
char	*get_next_line(int fd);
int		ft_atol(const char *s);
void	check_order(t_stacks *stacks);
int		slen(char *c);
int		ft_strchr(char *str, int c);
int		ft_abs_value(int nb);
int		ft_larger_nb(int a, int b);
void	check_args(char **args);
void	check_double(int *tab, int len);
t_tab	largest_increasing_sequence(int *tab, int len);
t_tab	get_lis(t_lis lis_t, int *tab, int len);
void	pa(t_stacks *stacks, int i);
void	pb(t_stacks *stacks, int i);
void	sa(t_stacks *stacks, int i);
void	sb(t_stacks *stacks, int i);
void	ss(t_stacks *stacks, int i);
void	ra(t_stacks *stacks, int i);
void	rb(t_stacks *stacks, int i);
void	rr(t_stacks *stacks, int i);
void	rra(t_stacks *stacks, int i);
void	rrb(t_stacks *stacks, int i);
void	rrr(t_stacks *stacks, int i);
void	push_to_b(t_stacks *stacks, t_tab lis);
void	do_best_move(t_stacks *stacks);
int		nb_position(t_stacks *stacks, int nb);
void	push_a(t_stacks *stacks, t_moves moves);
void	rotate_to_finish(t_stacks *stacks);

#endif