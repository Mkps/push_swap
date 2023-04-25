/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:09:24 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 14:43:56 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_single(t_list *stack, char id)
{
	t_list tmp;
	tmp = get_last_elem(stack);
	while (stack->next != NULL)
	{
		stack = stack->next;
		stack->next = stack->next->next;
	}
}
