/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:03:10 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 07:09:34 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "get_next_line.h"

void	move_extend(int i, char ***buf, t_list ***stack_a, t_list **stack_b)
{
	if (ft_strcmp(*buf[i], "rra\n") == 0)
		rrotate_single(*stack_a, 'o');
	if (ft_strcmp(*buf[i], "rrb\n") == 0)
		rrotate_single(*stack_b, 'o');
	if (ft_strcmp(*buf[i], "rrr\n") == 0)
		rrotate_both(*stack_a, *stack_b, 'o');
	if (ft_strcmp(*buf[i], "sa\n") == 0)
		swap_single(*stack_a, 'o');
	if (ft_strcmp(*buf[i], "sb\n") == 0)
		swap_single(*stack_b, 'o');
	if (ft_strcmp(*buf[i], "ss\n") == 0)
		swap_both(*stack_a, *stack_b, 'o');
}

void	exec_move(char ***buf, t_list ***stack_a, t_list ***stack_b)
{
	int	i;

	i = 0;
	while (*buf[i])
	{
		if (ft_strcmp(*buf[i], "pa\n") == 0)
			push(*stack_a, *stack_b, 'o');
		if (ft_strcmp(*buf[i], "pb\n") == 0)
			push(*stack_b, *stack_a, 'o');
		if (ft_strcmp(*buf[i], "ra\n") == 0)
			rotate_single(*stack_a, 'o');
		if (ft_strcmp(*buf[i], "rb\n") == 0)
			rotate_single(*stack_b, 'o');
		if (ft_strcmp(*buf[i], "rr\n") == 0)
			rotate_both(*stack_a, *stack_b, 'o');
		move_extend(i, buf, stack_a, stack_b);
		free(*buf[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		size;
	t_list	**stack_a;
	t_list	**stack_b;
	char	**move_list;

	size = elem_number(argc, argv);
	move_list = malloc(sizeof (char *) * 100);
	if (argc < 2)
		return (0);
	stack_a = create_stack(size);
	stack_b = create_stack(size);
	tab = import_args(argc, argv);
	if (parse_error(tab))
		return (exit_handler(argc, stack_a, stack_b, tab));
	init_stack(stack_a, stack_b, tab);
	input_move(&move_list);
	exec_move(&move_list, &stack_a, &stack_b);
	output_OK(is_sorted(stack_a) && *stack_b == NULL);
	free(move_list);
	if (!exit_handler(argc, stack_a, stack_b, tab))
		return (1);
	return (0);
}
