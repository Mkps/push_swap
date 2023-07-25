/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alx <alx@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:33:27 by aloubier          #+#    #+#             */
/*   Updated: 2023/07/25 08:39:36 by alx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include "../../../includes/ft_push_swap.h"

int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *str, char c);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_atoi(const char *str);
size_t	ft_abs(int value);

#endif
