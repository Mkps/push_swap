/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:17:00 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 14:10:33 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//swap the first two elements on the specified stack.
void	swap_elem(t_list *elem, char stack)
{
	if (!elem)
	{
		printf("Invalid element provided to swap_elem, Stack swapped: %c", stack);
		return ;
	}
	if (stack == 'a')
		write(1, "sa", 2);
	else if (stack == 'b')
		write(1, "sb", 2);
	else
	{
		printf("invalid stack identifier provided to swap_elem, Stack swapped: %c", stack);
		return ;
	}
}

//Swap both elements at the same time;
void	swap_both(t_list *elem_a, t_list *elem_b)
{
	if (!elem_a || !elem_b)
		printf("Invalid element provided to swap_both.");
	swap_elem(elem_a, 'a');
	swap_elem(elem_b, 'b');
	write(1, "ss", 2);
}

//Push an element from a pile onto the other pile. Does nothing if pile_from is empty.
void	push_elem(t_list *pile_from, t_list *pile_to, char id)
{
	if (!pile_from || !pile_to)
		printf("Invalid element provided to push_elem, Stack swapped: %c", id);
}
