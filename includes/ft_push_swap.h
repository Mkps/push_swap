/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/25 11:40:37 by alx              ###   ########.fr       */
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
# include "../libft/libft.h"

typedef struct s_list	t_list;

struct s_list
{
	t_list	*next;
	int		value;
};

/**		Libft functions	**/
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *str, char c);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, t_list *node);
t_list	*ft_lstnew(int value);
int		ft_atoi(const char *str);
/**		Operations	**/
void	swap_single(t_list **stack, char id);	
void	swap_both(t_list **stack_a, t_list **stack_b, char id);
void	push(t_list **pile_from, t_list **pile_to, char id);
void	rotate_single(t_list **stack, char id);
void	rotate_both(t_list **stack_a, t_list **stack_b, char id);
void	rrotate_single(t_list **stack, char id);
void	rrotate_both(t_list **stack_a, t_list **stack_b, char id);
/**		Utils	**/
int		elem_number(int argc, char **argv);
size_t	ft_abs(int number);
int		parse_error(char **value);
char	**import_args(int size, char **argv);
t_list	**create_stack(int size); 
int		init_stack(t_list **stack_a, t_list **stack_b, char	**tab);
int		exit_handler(int argc, t_list **stack_a, t_list **stack_b, char **tab);
int		is_sorted(t_list **stack);
int		is_sorted_d(t_list **stack);
int		find_median(t_list **stack, int chunk_size);
int		find_target_value(t_list **stack, int value);
int		find_min(t_list **stack);
int		find_max(t_list **stack);
int		cost_compute_d(t_list **stack, int value, char mode);
int		cost_compute_a(t_list **stack, int value, char mode);
int		cost_compute(t_list **stack, int target);
int		double_rotation_evaluation(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
/**		Sorting	functions	**/
void	sort_main(t_list **stack_a, t_list **stack_b);
void	divide_stack(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a, t_list **stack_b);
void	basic_stack_sort(t_list **stack, char id);
void	basic_stack_sort_d(t_list **stack_a, t_list **stack_b);
/**		Display **/
void	output_move(char *mv);
void	output_error(void);
void	output_stack(t_list **stack);
void	output_OK(int OK);
/**		extending functions */
void	rot_divide(t_list **stack_a, t_list **stack_b);
void	ext_stack_sort(t_list **stack, char id, int i, int size);
void	ext_sort_three(t_list **stack, int c, int n, int l);
void	do_s_rotate(t_list **stack, char id, int *cost);
void	do_s_rrotate(t_list **stack, char id, int *cost);
void	do_d_rotate(t_list **s_a, t_list **s_b, int *c_a, int *c_b);
void	do_d_rrotate(t_list **s_a, t_list **s_b, int *c_a, int *c_b);

#endif
