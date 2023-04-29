/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:17:00 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 17:12:57 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_single(t_list **stack, char id)
{
	t_list	*next;
	t_list	*current;

	current = *stack;
	if (current->next == NULL || !*stack)
		return ;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*stack = next;
	if (id == 'a')
		output_move("sa");
	else
		output_move("sb");
}

void	swap_both(t_list **stack_a, t_list **stack_b)
{
	swap_single(stack_a, 'a');
	swap_single(stack_b, 'b');
	write(1, "ss", 2);
}

void	push_elem(t_list *pile_from, t_list *pile_to, char id)
{
	if (!pile_from || !pile_to)
		printf("Invalid element: %c", id);
}
