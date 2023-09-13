/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:12:37 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/24 16:12:37 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_bool	is_overflow(t_ll number);
static t_bool	is_double(int new, t_list *lst);

t_exit	parsing(char **av, t_list **lst)
{
	int		i;
	t_ll	res;

	i = 0;
	while (av[i])
	{
		if (is_number(av[i]) == FALSE)
			return (ERROR);
		res = ft_atoi(av[i]);
		if (is_overflow(res))
			return (ERROR);
		if (is_double((int)res, *lst))
			return (ERROR);
		ft_lstadd_back(lst, (int)res);
		i++;
	}
	return (SUCCESS);
}

static	t_bool	is_overflow(t_ll number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_double(int new, t_list *lst)
{
	while (lst)
	{
		if (lst->data == new)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
