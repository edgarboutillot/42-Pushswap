/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:04 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/12 13:59:04 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*dup_tab(t_list *top_a, int len);
static void	sort_tab(int *tab, int len);
static int	get_index(int *tab, int value, int len);

t_exit	set_index(t_list *top_a)
{
	int	*tab;
	int	len;

	len = ft_lst_size(top_a);
	tab = dup_tab(top_a, len);
	if (!tab)
		return (ERROR_MALLOC);
	sort_tab(tab, len);
	while (top_a)
	{
		top_a->data = get_index(tab, top_a->data, len);
		top_a = top_a->next;
	}
	free(tab);
	return (SUCCESS);
}

static int	*dup_tab(t_list *top_a, int len)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	while (top_a)
	{
		tab[i] = top_a->data;
		top_a = top_a->next;
		i++;
	}
	return (tab);
}

static void	sort_tab(int *tab, int len)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static int	get_index(int *tab, int value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == value)
			break ;
		i++;
	}
	return (i);
}
