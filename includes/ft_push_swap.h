/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 14:16:31 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list t_list;

struct s_list
{
	t_list	*next;
	int		value;
};

void	swap_elem(t_list *elem, char stack);
void	swap_both(t_list *elem_a, t_list *elem_b);
void	push_elem(t_list *pile_from, t_list *pile_to, char id);
int		elem_number(int argc, char **argv);

#endif
