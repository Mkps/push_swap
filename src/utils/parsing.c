/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:18:48 by aloubier          #+#    #+#             */
/*   Updated: 2023/08/22 16:20:28 by aloubier         ###   ########.fr       */
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

/** Check if string will overflow an int type. Returns 1 if it does **/
static int	is_overflow(char *value)
{
	int			i;
	int			sign;
	long long	nb;

	i = 0;
	while (value[i] && ((value[i] >= 9
				&& value[i] <= 13) || value[i] == 32))
		i++;
	sign = 1;
	if (value[i] == '+' || value[i] == '-')
	{
		if (value[i] == '-')
			sign = -1;
		i++;
	}
	nb = 0;
	while (value[i] && (value[i] >= '0' && value[i] <= '9'))
	{
		nb = (nb * 10) + value[i++] - '0';
		if (nb * sign > INT_MAX || nb * sign < INT_MIN)
			return (EXIT_FAILURE);
	}
	nb *= sign;
	return (EXIT_SUCCESS);
}

/** Parse the provided string array for overflowing arguments **/
static int	parse_overflow(char **value)
{
	int			i;

	i = 0;
	while (value[i] != NULL)
	{
		if (is_overflow(value[i]))
			return (output_error(), 1);
		else
			i++;
	}
	return (0);
}

/**	Handler for the parsing functions.	**/
int	parse_error(char **value, int argc)
{
	int	i;

	i = 0;
	while (value[i] && value[i][0])
		i++;
	if (value[0] == 0 || i < argc - 1)
		return (output_error(), 1);
	if (parse_invalid(value) == 1)
		return (1);
	if (parse_duplicate(value) == 1)
		return (1);
	if (parse_overflow(value) == 1)
		return (1);
	return (0);
}
