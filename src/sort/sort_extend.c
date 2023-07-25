/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:26:23 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 07:28:52 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rot_divide(t_list **stack_a, t_list **stack_b)
{
	if (double_rotation_evaluation(stack_a, stack_b) == 1)
		rotate_both(stack_a, stack_b, 'r');
	else
		rotate_single(stack_a, 'a');
}

void	ext_stack_sort(t_list **stack, char id, int i, int size)
{
	if (i < size / 2)
		rotate_single(stack, id);
	else
		rrotate_single(stack, id);
}
