/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:03:10 by alx               #+#    #+#             */
/*   Updated: 2023/08/22 16:09:15 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "get_next_line.h"

void	move_extend(int value, t_list **stack_a, t_list **stack_b)
{
	if (value == RRA_VALUE)
		rrotate_single(stack_a, 'o');
	if (value == RRB_VALUE)
		rrotate_single(stack_b, 'o');
	if (value == RRR_VALUE)
		rrotate_both(stack_a, stack_b, 'o');
	if (value == SA_VALUE)
		swap_single(stack_a, 'o');
	if (value == SB_VALUE)
		swap_single(stack_b, 'o');
	if (value == SS_VALUE)
		swap_both(stack_a, stack_b, 'o');
}

void	exec_move(t_list **head, t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *head;
	while (current)
	{
		if (current->value == PA_VALUE)
			push(stack_b, stack_a, 'o');
		if (current->value == PB_VALUE)
			push(stack_a, stack_b, 'o');
		if (current->value == RA_VALUE)
			rotate_single(stack_a, 'o');
		if (current->value == RB_VALUE)
			rotate_single(stack_b, 'o');
		if (current->value == RR_VALUE)
			rotate_both(stack_a, stack_b, 'o');
		move_extend(current->value, stack_a, stack_b);
		current = current->next;
	}
}

int	init_stacks(t_list **move_list, t_list **stack_a, t_list **stack_b)
{
	stack_a = create_stack(1);
	if (!stack_a)
		return (EXIT_FAILURE);
	stack_b = create_stack(1);
	if (!stack_b)
	{
		free(stack_a);
		return (EXIT_FAILURE);
	}
	move_list = create_stack(1);
	if (!move_list)
	{
		free(stack_a);
		free(stack_a);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		size;
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	**move_list;

	size = elem_number(argc, argv);
	if (argc < 2)
		return (0);
	if (init_stacks == EXIT_FAILURE)
		return (EXIT_FAILURE);
	tab = import_args(argc, argv);
	if (parse_error(tab))
		return (exit_handler(argc, stack_a, stack_b, tab));
	init_stack(stack_a, stack_b, tab);
	if (input_move(move_list) == EXIT_SUCCESS)
	{
		exec_move(move_list, stack_a, stack_b);
		output_ok(is_sorted(stack_a) && *stack_b == NULL);
	}
	ft_lstclear(move_list);
	free(move_list);
	if (!exit_handler(argc, stack_a, stack_b, tab))
		return (1);
	return (0);
}
