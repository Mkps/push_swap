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

void	rotate_single(t_list *stack, char id)
{
	t_list	*tmp;

	tmp = ft_lstlast(stack);
	while (stack->next != NULL)
	{
		stack = stack->next;
		stack->next = stack->next->next;
	}
	if (id == 'a')
		write(1, "ra", 2);
	else if (id == 'b')
		write(1, "rb", 2);
}
