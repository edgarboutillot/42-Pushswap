/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:30:26 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/12 18:30:26 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	solve_three(t_list **top_a);
static void	solve_five(t_list **top_a, t_list **top_b);
static void	push_max(t_list **top_a, t_list **top_b);

void	solve(t_list **top_a, t_list **top_b)
{
	int	size;

	if (ft_lst_is_sort(*top_a))
		return ;
	size = ft_lst_size(*top_a);
	if (size == 3)
		solve_three(top_a);
	else if (size == 5)
		solve_five(top_a, top_b);
	else
		solve_radix(top_a, top_b);
}

static void	solve_three(t_list	**top_a)
{
	int	first;
	int	second;

	first = (*top_a)->data;
	second = (*top_a)->next->data;
	if (first == 0 && second == 2)
	{
		reverse_rotate_a(top_a);
		swap_a(top_a);
	}
	else if (first == 1 && second == 0)
		swap_a(top_a);
	else if (first == 1 && second == 2)
		reverse_rotate_a(top_a);
	else if (first == 2 && second == 1)
	{
		swap_a(top_a);
		reverse_rotate_a(top_a);
	}
	else if (first == 2 && second == 0)
		rotate_a(top_a);
}

static void	solve_five(t_list **top_a, t_list **top_b)
{
	push_max(top_a, top_b);
	push_max(top_a, top_b);
	solve_three(top_a);
	push_a(top_a, top_b);
	rotate_a(top_a);
	push_a(top_a, top_b);
	rotate_a(top_a);
}

static void	push_max(t_list **top_a, t_list **top_b)
{
	int	max;
	int	index;

	max = ft_lst_size(*top_a) - 1;
	index = ft_lst_get_index(*top_a, max);
	if (index <= ft_lst_size(*top_a) / 2)
	{
		while ((*top_a)->data != max)
			rotate_a(top_a);
	}
	else
	{
		while ((*top_a)->data != max)
			reverse_rotate_a(top_a);
	}
	push_b(top_a, top_b);
}
