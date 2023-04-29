/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:52:54 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 18:59:14 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		size;
	t_list	**stack_a;
	t_list	**stack_b;

	size = elem_number(argc, argv);
	stack_a = create_stack(size);
	stack_b = create_stack(size);
	if (argc < 2)
		return (0);
	tab = import_args(argc, argv);
	if (tab)
	{
		parse_error(tab);
	}
	init_stack(stack_a, stack_b, tab);
	output_stack(stack_a);
	output_stack(stack_b);
	//rotate_single(stack_a, 'a');
	swap_single(stack_a, 'a');
	push(stack_a, stack_b, 'a');
	output_stack(stack_a);
	output_stack(stack_b);
	if (!exit_handler(argc, stack_a, stack_b, tab))
		return (1);
	return (0);
}
