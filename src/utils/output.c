/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:59:34 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 16:06:33 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	output_error(void);
{
	write(1, "Error\n", 6);
}

void	output_move(char *mv)
{
	if (ft_strcmp(mv, "sa"))
		write(1, "sa", 2);
	else if (ft_strcmp(mv, "sb"))
		write(1, "sb", 2);
	else if (ft_strcmp(mv, "ra"))
		write(1, "pa", 2);
	else if (ft_strcmp(mv, "rb"))
		write(1, "pb", 2);
	else if (ft_strcmp(mv, "ra"))
		write(1, "ra", 2);
	else if (ft_strcmp(mv, "rb"))
		write(1, "rb", 2);
	else if (ft_strcmp(mv, "rr"))
		write(1, "rr", 2);
	else if (ft_strcmp(mv, "rra"))
		write(1, "rra", 3);
	else if (ft_strcmp(mv, "rrb"))
		write(1, "rrb", 3);
	else if (ft_strcmp(mv, "rrr"))
		write(1, "rrr", 3);
	else
		output_error();
}
