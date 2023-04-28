/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:24 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 17:14:18 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_single(t_list **stack, char id)
{
	t_list	*last;
	t_list	*current;

	last = ft_lstlast(*stack);
	current = *stack;
	if (current == last || !*stack)
		return ;
	while (current->next->next)
		current = current->next;
	ft_lstadd_front(stack, last);
	current->next = NULL;
	if (id == 'a')
		write(1, "ra", 2);
	else if (id == 'b')
		write(1, "rb", 2);
}
