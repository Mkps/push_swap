/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 18:58:14 by aloubier         ###   ########.fr       */
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
t_list	*ft_lstnew(int value);
int		ft_atoi(const char *str);
/**		Operations	**/
void	swap_single(t_list **stack, char id);
void	swap_both(t_list **stack_a, t_list **stack_b);
void	push(t_list **pile_from, t_list **pile_to, char id);
void	rotate_single(t_list **stack, char id);
void	rotate_both(t_list **stack_a, t_list **stack_b);
void	rrotate_single(t_list **stack, char id);
void	rrotate_both(t_list **stack_a, t_list **stack_b);
/**		Utils	**/
int		elem_number(int argc, char **argv);
int		parse_error(char **value);
char	**import_args(int size, char **argv);
t_list	**create_stack(int size);
int		init_stack(t_list **stack_a, t_list **stack_b, char	**tab);
int		exit_handler(int argc, t_list **stack_a, t_list **stack_b, char **tab);
int		is_sorted(t_list **stack);
/**		Utils/Display **/
void	output_move(char *mv);
void	output_error(void);
void	output_stack(t_list **stack);

#endif
