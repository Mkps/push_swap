/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:17:00 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 13:40:12 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//swap the first two elements on the specified stack.
void	swap_elem(t_list elem, char stack)
{
	if (!elem)
	{
		ft_printf("Invalid element provided to swap_elem, Stack swapped: %c", stack);
		return (NULL)
	}
	if (stack == 'a')
		write(1, "sa", 2);
	else if (stack == 'b')
		write(1, "sb", 2);
	else
	{
		ft_printf("invalid stack identifier provided to swap_elem, Stack swapped: %c", stack);
		return (NULL);
	}
}

//Swap both elements at the same time;
void	swap_both(t_list elem_a, char elem_b)
{
	if (!elem_a || !elem_b)
		ft_printf("Invalid element provided to swap_both, Stack swapped: %c", stack);
	swap_elem(elem_a, 'a');
	swap_elem(elem_b, 'b');
	write(1, "ss", 2);
}

//Push an element from a pile onto the other pile. Does nothing if pile_from is empty.
void	push_elem(t_list pile_from, t_list pile_to, char id)
{
	if (!pile_from || !pile_to)
		ft_printf("Invalid element provided to push_elem, Stack swapped: %c", id);
}
