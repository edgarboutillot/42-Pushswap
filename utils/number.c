/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:09:45 by edboutil          #+#    #+#             */
/*   Updated: 2023/04/27 11:09:45 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1] != '\0'))
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] == '\0' && i != 0)
		return (TRUE);
	return (FALSE);
}

t_ll	ft_atoi(const char *str)
{
	int		i;
	t_ll	result;
	t_ll	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (((str[i] == 32) || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && is_digit(str[i]))
		result = result * 10 + (str[i++] - 48);
	return (result * sign);
}
