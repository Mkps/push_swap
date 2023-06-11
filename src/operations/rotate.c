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

void	rrotate_single(t_list **stack, char id)
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
		output_move("rra");
	else if (id == 'b')
		output_move("rrb");
}

void	rrotate_both(t_list **stack_a, t_list **stack_b, char id)
{
	t_list	*last;
	t_list	*current;

	last = ft_lstlast(*stack_a);
	current = *stack_a;
	if (current == last || !*stack_a)
		return ;
	while (current->next->next)
		current = current->next;
	ft_lstadd_front(stack_a, last);
	current->next = NULL;
	last = ft_lstlast(*stack_b);
	current = *stack_b;
	if (current == last || !*stack_b)
		return ;
	while (current->next->next)
		current = current->next;
	ft_lstadd_front(stack_b, last);
	current->next = NULL;
	if (id != 'o')
		output_move("rrr");
}

void	rotate_single(t_list **stack, char id)
{
	t_list	*current;

	current = *stack;
	if (current->next == NULL || !*stack)
		return ;
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
	t_list	*current;

	current = *stack_a;
	if (current->next == NULL || !*stack_a)
		return ;
	ft_lstadd_back(stack_a, current);
	*stack_a = current->next;
	current->next = NULL;
	current = *stack_b;
	if (current->next == NULL || !*stack_b)
		return ;
	ft_lstadd_back(stack_b, current);
	*stack_b = current->next;
	current->next = NULL;
	if (id != 'o')
		output_move("rr");
}
