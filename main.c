/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:19:18 by edboutil          #+#    #+#             */
/*   Updated: 2023/06/02 11:43:40 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*top_a;
	t_list	*top_b;

	ac--;
	av++;
	top_a = NULL;
	top_b = NULL;
	if (parsing(av, &top_a) == ERROR)
	{
		put_str_fd("Error\n", STDERR);
		ft_lstclear(top_a);
		return (ERROR);
	}
	if (set_index(top_a) == ERROR_MALLOC)
	{
		ft_lstclear(top_a);
		return (ERROR_MALLOC);
	}
	solve(&top_a, &top_b);
	ft_lstclear(top_a);
	return (SUCCESS);
}
