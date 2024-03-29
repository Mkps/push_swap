/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:01:41 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 08:41:57 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Takes in an integer and returns its' absolute value as unsigned int. */
size_t	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	return (number * -1);
}
