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

void	swap_elem(t_list *elem, char stack)
{
	if (!elem)
	{
		return ;
	}
	if (stack == 'a')
		write(1, "sa", 2);
	else if (stack == 'b')
		write(1, "sb", 2);
	else
	{
		return ;
	}
}

void	swap_both(t_list *elem_a, t_list *elem_b)
{
	if (!elem_a || !elem_b)
		printf("Invalid element provided to swap_both.");
	swap_elem(elem_a, 'a');
	swap_elem(elem_b, 'b');
	write(1, "ss", 2);
}

void	push_elem(t_list *pile_from, t_list *pile_to, char id)
{
	if (!pile_from || !pile_to)
		printf("Invalid element: %c", id);
}
