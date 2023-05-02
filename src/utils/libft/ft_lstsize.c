/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:42:01 by aloubier          #+#    #+#             */
/*   Updated: 2022/11/28 12:45:32 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	size_t	size;
	t_list	*current;

	size = 0;
	current = *lst;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}
