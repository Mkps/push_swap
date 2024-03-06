/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:14:24 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 10:31:38 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b);
void	push_index(t_list **stack_a, t_list **stack_b);

/** Handler for the sorting functions. */
void	sort_main(t_list **stack_a, t_list **stack_b)
{
	divide_stack(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	basic_stack_sort(stack_a, 'a');
}

/**Sort 3 items with the lowest amount of moves. */
void	sort_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*c;
	t_list	*n;
	t_list	*l;

	c = *stack_a;
	n = c->next;
	if (n->next == NULL)
	{
		if (c->value > n->value)
			swap_single(stack_a, 'a');
		if (!stack_b)
			return ;
	}
	l = n->next;
	ext_sort_three(stack_a, c->value, n->value, l->value);
	if (!stack_b)
		return ;
}

void	ext_cost_compute(int *c_a, int *c_b, t_list **s_a, t_list **s_b)
{
	t_list	*node_b;
	int		tmp_a;
	int		tmp_b;
	int		target;
	int		val;

	val = INT_MIN;
	node_b = *s_b;
	while (node_b != NULL)
	{
		tmp_b = cost_compute(s_b, node_b->value);
		target = find_target_value(s_a, node_b->value);
		tmp_a = cost_compute(s_a, target);
		if (ft_abs(tmp_a) + ft_abs(tmp_b) < ft_abs(*c_a) + ft_abs(*c_b)
			|| (ft_abs(tmp_a) + ft_abs(tmp_b) + (val - node_b->value)
				<= ft_abs(*c_a) + ft_abs(*c_b) && node_b->value > val))
		{
			if (val > node_b->value)
				val = node_b->value;
			*c_a = tmp_a;
			*c_b = tmp_b;
		}
		node_b = node_b->next;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	int		cost_a;
	int		cost_b;

	node_b = *stack_b;
	cost_a = 10000;
	cost_b = 10000;
	while (node_b != NULL)
	{
		ext_cost_compute(&cost_a, &cost_b, stack_a, stack_b);
		while (cost_a || cost_b)
		{
			do_d_rotate(stack_a, stack_b, &cost_a, &cost_b);
			do_s_rotate(stack_a, 'a', &cost_a);
			do_s_rotate(stack_b, 'b', &cost_b);
			do_d_rrotate(stack_a, stack_b, &cost_a, &cost_b);
			do_s_rrotate(stack_a, 'a', &cost_a);
			do_s_rrotate(stack_b, 'b', &cost_b);
		}
		push(stack_b, stack_a, 'b');
		cost_a = 10000;
		cost_b = 10000;
		node_b = *stack_b;
	}
}
