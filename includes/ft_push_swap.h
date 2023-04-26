/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 18:24:20 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list	t_list;

struct s_list
{
	t_list	*next;
	int		value;
};


/**		Libft functions	**/
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *str, char c);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
/**		Operations	**/
void	swap_elem(t_list *elem, char stack);
void	swap_both(t_list *elem_a, t_list *elem_b);
void	push_elem(t_list *pile_from, t_list *pile_to, char id);
/**		Utils	**/
int		parse_error(char **value);
int		init_stack(t_list **root, char	**value);
t_list	**create_stack(void);
int		elem_number(int argc, char **argv);
void	output_move(char *mv);
void	output_error(void);

#endif
