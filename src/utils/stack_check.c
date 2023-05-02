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
	while (i + 1 < nb)
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
	tmp = tab[(nb + 1) / 2];
	free(tab);
	return tmp;
}
