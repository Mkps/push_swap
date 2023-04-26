#include "ft_push_swap.h"

//Computes the number of elements in the stack.
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
	printf("size is %i", size);
	return (size);
}

//Returns the root of a stack
t_list	**create_stack(void)
{
	t_list	**new;

	new = malloc(sizeof(t_list*));
	if(!new)
		return(NULL);
	return (new);
}

//Initialize stack a with the provided values. Returns 1 in case of error.
int	init_stack(t_list **root, char	**value)
{
	t_list	*new;
	t_list	*tmp;
	int		i;

	i = 0;
	while (value[i] != NULL)
	{
		tmp = get_last_elem(root);
		new = malloc(sizeof (t_list));
		if (!new)
			return (1);
		new->next = NULL;
		tmp->next = new;
		new->value = ft_atoi(value[i]);
		i++;
	}
	return (0);
}
