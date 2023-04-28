/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:59:13 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/28 17:01:21 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/** Computes the number of elements in the stack. **/
int	elem_number(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

/** Returns the root of a stack **/
t_list	**create_stack(int size)
{
	t_list	**stack;

	stack = malloc(sizeof (t_list *) * size);
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}

/**	Import the args into a fresh tab **/
char	**import_args(int argc, char **argv)
{
	int		i;
	int		size;
	char	**tab;

	i = 0;
	size = elem_number(argc, argv);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = malloc(sizeof (char *) * (size + 1));
		if (!tab)
			return (NULL);
		tab[size] = 0;
		while (argv [i + 1] != NULL)
		{
			tab[i] = argv[i + 1];
			i++;
		}
	}
	return (tab);
}

/**	Initialize stack a with the provided values. Returns 1 in case of error. **/
int	init_stack(t_list **stack_a, t_list **stack_b, char	**tab)
{
	t_list	*new;
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(tab[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	*stack_b = NULL;
	return (0);
}
