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

int	find_median(t_list **stack)
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
	if (nb % 2 == 1)
		nb++;
	tmp = tab[nb / 2];
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
int	cost_compute_d(t_list **stack, int value)
{
	t_list	*current;
	int		cost_d;
	int		i;

	current = *stack;
	cost_d = 0;
	i = 0;
	while (current && cost_d == 0)
	{
		i++;
		if (current->value <= value)
			cost_d = i;
		current = current->next;
	}
	return (cost_d);
}

/** Finds the lowest cost to get the value onto the top of the stack from rr. */
int	cost_compute_a(t_list **stack, int value)
{
	t_list	*current;
	int		cost_a;
	int		i;

	current = *stack;
	cost_a = 0;
	i = 0;
	while (current && cost_a == 0)
	{
		i++;
		if (current->value <= value)
			cost_a = i;
		current = current->next;
	}
	return (cost_a);
}