/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:05:56 by alx               #+#    #+#             */
/*   Updated: 2023/08/22 16:16:10 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_push_swap.h"
#include "get_next_line.h"

int	move_value(char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		return (PA_VALUE);
	if (ft_strcmp(str, "pb\n") == 0)
		return (PB_VALUE);
	if (ft_strcmp(str, "ra\n") == 0)
		return (RA_VALUE);
	if (ft_strcmp(str, "rb\n") == 0)
		return (RB_VALUE);
	if (ft_strcmp(str, "rr\n") == 0)
		return (RR_VALUE);
	if (ft_strcmp(str, "rra\n") == 0)
		return (RRA_VALUE);
	if (ft_strcmp(str, "rrb\n") == 0)
		return (RRB_VALUE);
	if (ft_strcmp(str, "rrr\n") == 0)
		return (RRR_VALUE);
	if (ft_strcmp(str, "sa\n") == 0)
		return (SA_VALUE);
	if (ft_strcmp(str, "sb\n") == 0)
		return (SB_VALUE);
	if (ft_strcmp(str, "ss\n") == 0)
		return (SS_VALUE);
	return (0);
}

int	input_error(char *buf, t_list **head)
{
	printf("Error\n");
	ft_lstclear(head);
	free(buf);
	buf = get_next_line(-1);
	return (EXIT_FAILURE);
}

int	input_move(t_list **head)
{
	char	*buf;
	t_list	*new;

	new = *head;
	buf = "str";
	while (buf)
	{
		buf = get_next_line(0);
		if (!buf)
			return (EXIT_SUCCESS);
		if (!move_value(buf))
			return (input_error(buf, head));
		new = ft_lstnew(move_value(buf));
		if (!new)
			return (input_error(buf, head));
		ft_lstadd_back(head, new);
		free(buf);
	}
	return (EXIT_SUCCESS);
}
