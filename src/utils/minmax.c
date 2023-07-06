/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:46:31 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 19:00:44 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_min(t_list **stack)
{
	t_list	*current;
	int		min;

	current = *stack;
	min = current->value;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_max(t_list **stack)
{
	t_list	*current;
	int		max;

	current = *stack;
	max = INT_MIN;
	while (current != NULL)
	{
		if (current->value > max)
		{
			max = current->value;
		}
		current = current->next;
	}
	return (max);
}
