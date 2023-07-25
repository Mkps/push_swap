/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:46:31 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 19:00:44 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sort_tab(int *tab, int nb)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < nb - 1)
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
	return (tmp);
}

void	create_tab(t_list **stack, int *tab)
{
	t_list	*current;
	int		i;

	current = *stack;
	i = 0;
	while (current != NULL)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
}

int	find_median(t_list **stack, int chunk_size)
{
	int		nb;
	int		tmp;
	int		*tab;

	nb = ft_lstsize(stack);
	if (nb <= 3)
		return (0);
	tab = malloc(nb * sizeof (int));
	if (!tab)
		return (0);
	create_tab(stack, tab);
	tmp = sort_tab(tab, nb);
	if (nb - 3 < 0)
		tmp = tab[0];
	else if (nb < chunk_size)
		tmp = tab[nb - 2];
	else
	{
		while (nb % 2 != 0)
			nb++;
		tmp = tab[nb / 2];
	}
	free(tab);
	return (tmp);
}
