#include "ft_push_swap.h"

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

t_list	**init_stack(t_list **root)
{
	t_list	**new;
	t_list	*tmp;
	int		i;

	if (root == NULL)
	{
		new = (t_list**)malloc(sizeof(t_list**));
		if (!new)
			return (NULL);
		else
			return (new);
	}
	else
	{
		i = 0;
		while (args[i] != NULL)
		{
			tmp = malloc(sizeof(t_list));
			if (!tmp)
				return (NULL);
			tmp->next = NULL;
			tmp->value = ft_atoi(args[i]);
			ft_get_last_elem(root)->next = tmp;
			i++;
		}
	}

}