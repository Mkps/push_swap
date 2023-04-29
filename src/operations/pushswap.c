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
	output_move("ss");
}

void	push(t_list **pile_from, t_list **pile_to, char id)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *pile_from;
	next = *pile_to;
	if (!*pile_from)
		return ;
	*pile_from = tmp->next;
	*pile_to = tmp;
	tmp->next = next;
	if (id == 'a')
		output_move("pa");
	else
		output_move("pb");
}
