/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:23:46 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/27 11:23:46 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_list **top)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(*top) || !(*top)->next)
		return ;
	tmp1 = *top;
	tmp2 = (*top)->next;
	*top = tmp2;
	tmp1->next = (*top)->next;
	tmp2->next = tmp1;
}

void	swap_a(t_list **top_a)
{
	swap(top_a);
	put_str_fd("sa\n", STDOUT);
}

void	swap_b(t_list **top_b)
{
	swap(top_b);
	put_str_fd("sb\n", STDOUT);
}

void	swap_both(t_list **top_a, t_list **top_b)
{
	swap(top_a);
	swap(top_b);
	put_str_fd("ss\n", STDOUT);
}
