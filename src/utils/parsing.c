/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:48 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/25 18:45:20 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_duplicate(char **value)
{
	char *tmp;
	int	i;
	int	current;

	i = 0;
	tmp = value[i];
	current = 0;
	while (value[current])
	{
		i = current;
		tmp = value[current];
		while (!value[i])
		{
			if (atoi(tmp) == atoi(value[i]))
				return (1);
			i++;
		}
		current++;
	}
	return (0);
}
