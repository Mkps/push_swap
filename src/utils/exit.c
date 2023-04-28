/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:08:59 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 17:55:47 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Clearing tab **/
static void	ft_tabclear(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/** Main function cleaning memory allocated **/
int	exit_handler(int argc, t_list **stack_a, t_list **stack_b, char **tab)
{
	ft_lstclear(stack_a);
	write(1, "a\n", 2);
	ft_lstclear(stack_b);
	write(1, "b\n", 2);
	if (argc == 2)
		ft_tabclear(tab);
	else
		free(tab);
	free(stack_a);
	free(stack_b);
	return (0);
}
