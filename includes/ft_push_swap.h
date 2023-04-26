/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/25 19:25:09 by aloubier         ###   ########.fr       */
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
int		parse_error(char **value);
int		init_stack(t_list **root, char	**value);
t_list	**create_stack(void);
int		elem_number(int argc, char **argv);
void	output_move(char *mv);
void	output_error(void);


#endif
