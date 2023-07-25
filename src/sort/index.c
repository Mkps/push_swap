/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:34:13 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 08:34:22 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ext_index(t_list **stack_a)
{
	t_list	*current;
	int		i_ind[3];
	int		i;

	i = 0;
	i_ind[2] = 0;
	current = *stack_a;
	i_ind[0] = current->value;
	i_ind[1] = i_ind[0];
	while (current->next != NULL && i++)
	{
		if (i > i_ind[2])
		{
			i_ind[2] = i;
			i_ind[1] = i_ind[0];
		}
		if (current->next->value < current->value)
		{
			i = 0;
			i_ind[0] = current->next->value;
		}
		i++;
		current = current->next;
	}
	return (i_ind[1]);
}

void	push_index(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		i_ind;

	current = *stack_a;
	i_ind = ext_index(stack_a);
	while (current->value != i_ind)
	{
		push(stack_a, stack_b, 'a');
		current = *stack_a;
	}
	while (current->next->value > current->value)
	{
		rotate_single(stack_a, 'a');
		current = *stack_a;
	}
	if (current->next->value < current->value)
		rotate_single(stack_a, 'a');
	current = *stack_a;
	while (current->value != i_ind)
	{
		push(stack_a, stack_b, 'a');
		current = *stack_a;
	}
}
