/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:26:31 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/12 15:34:41 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_list **top_from, t_list **top_to)
{
	t_list	*first;

	if (!*top_from)
		return ;
	first = *top_from;
	*top_from = (*top_from)->next;
	first->next = NULL;
	ft_lstadd_front(top_to, first);
}

void	push_a(t_list **top_a, t_list **top_b)
{
	push(top_b, top_a);
	put_str_fd("pa\n", STDOUT);
}

void	push_b(t_list **top_a, t_list **top_b)
{
	push(top_a, top_b);
	put_str_fd("pb\n", STDOUT);
}

void	push_all_a(t_list **top_a, t_list **top_b)
{
	while (*top_b)
		push_a(top_a, top_b);
}
