/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:59:34 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 17:16:20 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/** Outputs "Error" followed by a nl */
void	output_error(void)
{
	write(1, "Error\n", 6);
}

void	output_ok(int ok)
{
	if (ok == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/** Outputs the values currently contained in the stack passed as argument*/
void	output_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	tmp = *stack;
	printf("\n|||");
	if (*stack == NULL)
		printf("Empty");
	while (tmp)
	{
		current = tmp;
		tmp = current->next;
		printf("%i ", current->value);
	}
}

/** Outputs the move being done */
void	output_move(char *mv)
{
	if (mv)
		printf("%s\n", mv);
	else
		output_error();
}
