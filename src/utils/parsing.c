/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:48 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 17:11:11 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//Parse the provided string array for invalid characters

int	parse_invalid(char **value)
{
	int	i;
	int	j;

	i = 0;
	while (value[i] != NULL)
	{
		j = 0;
		if (value[i][j] == '+' || value[i][j] == '-'
				|| (value[i][j] >= '0' && value[i][j] <= '9'))
			j++;
		while (value[i][j] != NULL)
		{
			if (value[i][j] < '0' || value[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
}

int	parse_duplicate(char **value)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (value[i] != NULL)
	{
		j = 0;
		while (value[i + j] != NULL)
		{
			if (ft_atoi(value[i]) == ft_atoi(value[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
