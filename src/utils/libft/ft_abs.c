/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 07:01:41 by alx               #+#    #+#             */
/*   Updated: 2023/07/25 07:01:42 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Takes in an integer and returns its' absolute value as unsigned int. */
unsigned int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	return (number * -1);
}
