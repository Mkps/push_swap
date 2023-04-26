/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:52:54 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 14:24:35 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	elem_number(argc, argv);
	t_list	*new;
	new = malloc(sizeof (t_list));
	new->next = 0;
	new->value = 0;
	swap_elem(new, 'a');
	write(1, "hello", 5);
	return (0);
}
