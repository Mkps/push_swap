#include "ft_push_swap.h"

void    divide_stack(t_list **stack_a, t_list **stack_b)
{
    t_list	*current;
	int		nb;
	int		median;
	int		chunk_size;

	current = *stack_a;
	nb = ft_lstsize(stack_a);
	chunk_size = nb / 10;
	median = find_median(stack_a, chunk_size);
	if (nb % 2 == 0)
		median++;
	// printf("DEBUG cv %i md %i\n", current->value, median);
    while (ft_lstsize(stack_a) > 3)
    {
		if(current->value <= median)
		{
			push(stack_a, stack_b, 'a');
			if (median <= find_min(stack_a))
			{
				median = find_median(stack_a, chunk_size);
				nb = ft_lstsize(stack_a) / 4;
				if (nb % 2 == 0)
					median++;
			}
		}
		else
		{
			// printf("Debug cost med = %i a = %i cost b = %i", find_median(stack_b), cost_compute_a(stack_a, find_median(stack_a), 'v'), cost_compute_d(stack_a, find_median(stack_a), 'v'));
			if (cost_compute_a(stack_a, median, 'v') > cost_compute_d(stack_a, median, 'v'))
			{
			//	if (double_rotation_evaluation(stack_a, stack_b) == 1)
			//		rotate_both(stack_a, stack_b);
			//	else
					rotate_single(stack_a, 'a');
			}
			else
				rrotate_single(stack_a, 'a');
		}
		current = *stack_a;
		// output_stack(stack_a);
		// output_stack(stack_b);
		// printf("DEBUG cv %i md %i nb %i\n", current->value, median, nb);

    }
}

void	basic_stack_sort(t_list **stack, char id)
{
	t_list	*l1;
	t_list	*last;
	int		i;
	int		max;
	
	l1 = *stack;
	last = ft_lstlast(*stack);
	i = 0;
	max = find_max(stack);
	while (!is_sorted(stack))
	{
		if ((l1->value > l1->next->value) && l1->value != max)
			swap_single(stack, id);
		else if ((l1->value < l1->next->value) && l1->value > last->value)
			rrotate_single(stack, id);
		else
			rotate_single(stack, id);
		l1 = *stack;
		last = ft_lstlast(*stack);
		i++;
		// output_stack(stack);
		// printf("\nDEBUG iteration %i\n", i);
	}
}

void	basic_stack_sort_d(t_list **stack_a, t_list **stack_b)
{
	t_list	*l1;
	
	l1 = *stack_b;
	while (l1 != NULL)
	{
		if (l1->value == find_max(stack_b))
			push(stack_b, stack_a, 'b');
		else
		{
			// printf("Debug cost max = %i a = %i cost b = %i", find_max(stack_b), cost_compute_a(stack_b, find_max(stack_b), 'm'), cost_compute_d(stack_b, find_max(stack_b), 'm'));
			if (cost_compute_a(stack_b, find_max(stack_b), 'm') >= cost_compute_d(stack_b, find_max(stack_b), 'm'))
				rotate_single(stack_b, 'b');
			else
				rrotate_single(stack_b, 'b');
		}
		if (!is_sorted(stack_a))
			basic_stack_sort(stack_a, 'a');
		l1 = *stack_b;
	// output_stack(stack_a);
	// output_stack(stack_b);
	// printf("DEBUG l1 %i max %i\n", l1->value, find_max(stack_b));
	}
}

/** Returns 1 if using a double would be useful */
int	double_rotation_evaluation(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*last;
	t_list	*current;

	first = *stack_b;
	last = ft_lstlast(*stack_b);
	current = *stack_a;
	if (current == NULL || first == NULL || first->next == NULL)
		return (0);
	// printf("DEBUG first %i last %i\n", first->value, last->value);
	if (first->value < first->next->value && first->value < last->value)
		return (1);
	else
		return (0);
}

/** Returns the value of the target node in the other stack.*/
int	find_target_value(t_list **stack, t_list *node)
{
	t_list	*current;
	int		target;

	current = *stack;
	target = find_max(stack);
	while (current != NULL)
	{
		if (current->value > node->value && current->value < target)
			target = current->value;
		current = current->next;
	}
	return (target);
}