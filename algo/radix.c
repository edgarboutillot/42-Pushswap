/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:18:39 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/12 16:11:46 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		push_byte_0(t_list **top_a, t_list **top_b, int mask);
static t_bool	bit_is_0(int value, int mask);

void	solve_radix(t_list	**top_a, t_list	**top_b)
{
	int	mask;

	mask = 1;
	while (!ft_lst_is_sort(*top_a))
	{
		push_byte_0(top_a, top_b, mask);
		push_all_a(top_a, top_b);
		mask <<= 1;
	}
}

static void	push_byte_0(t_list **top_a, t_list **top_b, int mask)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lst_size(*top_a);
	while (i < size)
	{
		if (bit_is_0((*top_a)->data, mask))
			push_b(top_a, top_b);
		else
			rotate_a(top_a);
		i++;
	}
}

static t_bool	bit_is_0(int value, int mask)
{
	if ((value & mask) == 0)
		return (TRUE);
	else
		return (FALSE);
}
