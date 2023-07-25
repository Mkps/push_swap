/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:30:30 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 08:31:05 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	do_s_rotate(t_list **stack, char id, int *cost)
{
	while (*cost > 0)
	{
		rotate_single(stack, id);
		*cost -= 1;
	}
}

void	do_s_rrotate(t_list **stack, char id, int *cost)
{
	while (*cost < 0)
	{
		rrotate_single(stack, id);
		*cost += 1;
	}
}

void	do_d_rotate(t_list **s_a, t_list **s_b, int *c_a, int *c_b)
{
	while (*c_a > 0 && *c_b > 0)
	{
		rotate_both(s_a, s_b, 'r');
		*c_a -= 1;
		*c_b -= 1;
	}
}

void	do_d_rrotate(t_list **s_a, t_list **s_b, int *c_a, int *c_b)
{
	while (*c_a < 0 && *c_b < 0)
	{
		rrotate_both(s_a, s_b, 'r');
		*c_a += 1;
		*c_b += 1;
	}
}
