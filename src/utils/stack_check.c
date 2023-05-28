/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:46:31 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 19:00:44 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Checks if the values of the stack are ordered */
int	is_sorted(t_list	**stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		current = tmp;
		while (current->next != NULL)
		{
			current = current->next;
			if (tmp->value > current->value)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_d(t_list	**stack)
{
	t_list	*tmp;
	t_list	*current;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		current = tmp;
		while (current->next != NULL)
		{
			current = current->next;
			if (tmp->value < current->value)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	find_median(t_list **stack, int chunk_size)
{
	int		nb;
	int		tmp;
	int		i;
	int		*tab;
	t_list	*current;

	nb = ft_lstsize(stack);
	tab = malloc(nb * sizeof (int));
	if (!tab)
		return (0);
	current = *stack;
	i = 0;
	while (current != NULL)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
	while (nb % chunk_size != 0)
		nb++;
	if (nb == chunk_size)
		tmp = tab[0];
	else
		tmp = tab[chunk_size];
	free(tab);
	return tmp;
}

int	find_min(t_list **stack)
{
	t_list *current;
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
	t_list *current;
	int		max;

	current = *stack;
	max = current->value;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

/** Finds the lowest cost to get the value onto the top of the stack from r. */
int	cost_compute_d(t_list **stack, int value, char mode)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current)
	{
		i++;
		if (current->value <= value && mode == 'v')
			return (i);
		if (current->value == value && mode == 'm')
			return (i);
		current = current->next;
	}
	return (i);
}

/** Finds the lowest cost to get the value onto the top of the stack from rr. */
int	cost_compute_a(t_list **stack, int value, char mode)
{
	t_list	*current;
	int		i;
	int		last_index;
	int		size;

	current = *stack;
	size = ft_lstsize(stack);
	size++;
	last_index = 0;
	i = 0;
	while (current)
	{
		i++;
		if (current->value <= value && mode == 'v')
			last_index = i;
		if (current->value == value && mode == 'm')
			return (size - i);
		current = current->next;
	}
	return (size - last_index);
}
/** Computes the number of moves needed to get a node, identified by value, to the top of the stack.
 *  The returned value is negative if accessed by the bottom (ie reverse rotate). Positive otherwise.
*/
int cost_compute(t_list **stack, int target)
{
	t_list	*current;
	int		i;
	int		size;

	current = *stack;
	size = ft_lstsize(stack);
	i = 0;
	while (current)
	{
		if (current->value == target)
			break;
		current = current->next;
		i++;
	}
	if (i < size - i)
		return (i);
	else
		return ((size - i) * -1);
}