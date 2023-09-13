/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:07:03 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:07:03 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_list **top)
{
	t_list	*last;
	t_list	*tmp;

	if ((*top) == NULL || (*top)->next == NULL)
		return ;
	last = *top;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *top;
	*top = tmp;
}

void	reverse_rotate_a(t_list **top_a)
{
	put_str_fd("rra\n", STDOUT);
	reverse_rotate(top_a);
}

void	reverse_rotate_b(t_list **top_b)
{
	put_str_fd("rrb\n", STDOUT);
	reverse_rotate(top_b);
}

void	reverse_rotate_both(t_list **top_a, t_list **top_b)
{
	put_str_fd("rrr\n", STDOUT);
	reverse_rotate(top_a);
	reverse_rotate(top_b);
}
