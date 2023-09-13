/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:04:53 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:04:53 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_list **top)
{
	t_list	*first_elem;
	t_list	*last_elem;

	first_elem = *top;
	if (first_elem == NULL || first_elem->next == NULL)
		return ;
	last_elem = ft_lstlast(*top);
	last_elem->next = first_elem;
	*top = first_elem->next;
	first_elem->next = NULL;
}

void	rotate_a(t_list **top_a)
{
	put_str_fd("ra\n", STDOUT);
	rotate(top_a);
}

void	rotate_b(t_list **top_b)
{
	put_str_fd("rb\n", STDOUT);
	rotate(top_b);
}

void	rotate_both(t_list **top_a, t_list **top_b)
{
	put_str_fd("rr\n", STDOUT);
	rotate(top_a);
	rotate(top_b);
}
