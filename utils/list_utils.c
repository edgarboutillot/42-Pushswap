/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:25:57 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/19 10:25:57 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lst_size(t_list *top_a)
{
	int	i;

	i = 0;
	while (top_a != NULL)
	{
		top_a = top_a->next;
		i++;
	}
	return (i);
}

t_bool	ft_lst_is_sort(t_list *top_a)
{
	while (top_a && top_a->next)
	{
		if (top_a->next->data < top_a->data)
			return (FALSE);
		top_a = top_a->next;
	}
	return (TRUE);
}

int	ft_lst_get_index(t_list *top_a, int value)
{
	int	index;

	index = 0;
	while (top_a)
	{
		if (top_a->data == value)
			break ;
		top_a = top_a->next;
		index++;
	}
	return (index);
}

void	ft_lstclear(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
