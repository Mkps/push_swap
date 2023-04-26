/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:48 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 19:18:06 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Parse the provided string array for invalid characters **/
static int	parse_invalid(char **value)
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
		while (value[i][j] != 0)
		{
			if (value[i][j] >= '0' && value[i][j] <= '9')
				j++;
			else
				return (output_error(), 1);
		}
		i++;
	}
	return (0);
}

/** Parse the provided string array for duplicate arguments **/
static int	parse_duplicate(char **value)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (value[i] != NULL)
	{
		j = 1;
		while (value[i + j] != NULL)
		{
			if (ft_atoi(value[i]) == ft_atoi(value[i + j]))
				return (output_error(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

/** Parse the provided string array for overflowing arguments **/
static int	parse_overflow(char **value)
{
	long long	result;
	int			i;
	int			j;
	int			sign;

	result = 0;
	j = 0;
	while(value[j] != NULL)
	{

		i = 0;
		while (value[j][i] && ((value[j][i] >= 9 && value[j][i] <= 13) || value[j][i] == 32))
			i++;
		sign = 1;
		if (value[j][i] == '+' || value[j][i] == '-')
		{
			if (value[j][i] == '-')
				sign = -1;
			i++;
		}
		result = 0;
		while (value[j][i] && (value[j][i] >= '0' && value[j][i] <= '9'))
		{
			result *= 10;
			result += value[j][i] - '0';
			i++;
		}
		result *= sign;
		if (result > INT_MAX || result < INT_MIN)
			return (output_error(), 1);
		else
			j++;
	}
	return (0);
}
	
/**	Handler for the parsing functions.	**/
int	parse_error(char **value)
{
	if (parse_invalid(value) == 1)
		return (1);
	if (parse_duplicate(value) == 1)
		return (1);
	if (parse_overflow(value) == 1)
		return (1);
	return (0);
}
