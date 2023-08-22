/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:17:00 by aloubier          #+#    #+#             */
/*   Updated: 2023/08/22 15:26:51 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_single(t_list **stack, char id)
{
	t_list	*next;
	t_list	*current;

	if (!*stack)
		return ;
	current = *stack;
	if (current->next == NULL || current == NULL)
		return ;
	next = current->next;
	current->next = next->next;
	next->next = current;
	*stack = next;
	if (id == 'a')
		output_move("sa");
	if (id == 'b')
		output_move("sb");
}

void	swap_both(t_list **stack_a, t_list **stack_b, char id)
{
	swap_single(stack_a, 'a');
	swap_single(stack_b, 'b');
	if (id != 'o')
		output_move("ss");
}

void	push(t_list **pile_from, t_list **pile_to, char id)
{
	t_list	*tmp;
	t_list	*next;

	if (!*pile_from)
		return ;
	tmp = *pile_from;
	next = *pile_to;
	if (tmp == NULL)
		return ;
	*pile_from = tmp->next;
	*pile_to = tmp;
	tmp->next = next;
	if (id == 'a')
		output_move("pb");
	if (id == 'b')
		output_move("pa");
}
