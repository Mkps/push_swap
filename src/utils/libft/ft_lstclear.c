/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 18:21:42 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	while (*lst)
	{
		current = *lst;
		*lst = current->next;
		write(1, "FREE\n", 5);
		free(current);
	}
	*lst = NULL;
}
