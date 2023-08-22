/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:24 by aloubier          #+#    #+#             */
/*   Updated: 2023/08/22 15:28:07 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rrotate_single(t_list **stack, char id)
{
	t_list	*last;
	t_list	*current;

	if (!*stack)
		return ;
	last = ft_lstlast(*stack);
	current = *stack;
	if (current == last)
		return ;
	while (current->next->next)
		current = current->next;
	ft_lstadd_front(stack, last);
	current->next = NULL;
	if (id == 'a')
		output_move("rra");
	else if (id == 'b')
		output_move("rrb");
}

void	rrotate_both(t_list **stack_a, t_list **stack_b, char id)
{
	rrotate_single(stack_a, 'o');
	rrotate_single(stack_b, 'o');
	if (id != 'o')
		output_move("rrr");
}

void	rotate_single(t_list **stack, char id)
{
	t_list	*current;

	if (!*stack)
		return ;
	current = *stack;
	if (current->next == NULL)
		return ;
	*stack = current->next;
	ft_lstadd_back(stack, current);
	*stack = current->next;
	current->next = NULL;
	if (id == 'a')
		output_move("ra");
	else if (id == 'b')
		output_move("rb");
}

void	rotate_both(t_list **stack_a, t_list **stack_b, char id)
{
	rotate_single(stack_a, 'o');
	rotate_single(stack_b, 'o');
	if (id != 'o')
		output_move("rr");
}
