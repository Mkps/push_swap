/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:48 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 15:53:54 by aloubier         ###   ########.fr       */
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
		if (value[i][j] == '+' || value[i][j] == '-' || (value[i][j] >= '0' && value[i][j] <= '9'))
			j++;
		while (value[i][j] != NULL)
		{
			if ( value[i][j] < '0'|| value[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
}


int	parse_duplicate(char **value)
{
	char *tmp;
	int	i;
	int	j;
	int	current;


	j = 0;
	current = 1;
	while (value[i][0] != 0)
	{
		i = current;
		tmp = value[current];
		j = 0;
		while (value[current][j] != 0)
		{
			if (j == 0 && (value[current][j] == '-' 
				|| value[current][j] == '+'))
				j++;
			if ( value[current][j] <= '0'|| value[current][j] >= '9')
			{
				return (1);
			}
			j++;
		}
		/*
		while (value[i + 1][0] != 0)
		{
			if (atoi(tmp) == atoi(value[i]))
			{
				//printf("Value of tmp: %i  Value of current value %i\n", atoi(tmp), atoi(value[i+1]));
				return (1);
			}
			i++;
		}*/
		current++;
	}
	return (0);
}
	
