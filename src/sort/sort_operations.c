#include "ft_push_swap.h"

void	divide_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		nb;
	int		median;
	int		chunk_size;

	current = *stack_a;
	nb = ft_lstsize(stack_a);
	chunk_size = 2;
	if (nb > 10)
		chunk_size = nb / 2;
	median = find_median(stack_a, chunk_size);
	while (ft_lstsize(stack_a) > 3)
	{
		if (current->value <= median)
		{
			push(stack_a, stack_b, 'a');
			if (median <= find_min(stack_a))
				median = find_median(stack_a, chunk_size);
		}
		else
		{
			if (double_rotation_evaluation(stack_a, stack_b) == 1)
				rotate_both(stack_a, stack_b, 'r');
			else
				rotate_single(stack_a, 'a');
		}
		current = *stack_a;
	}
}

void	basic_stack_sort(t_list **stack, char id)
{
	t_list	*l1;
	int		size;
	int		i;
	int		max;

	l1 = *stack;
	size = ft_lstsize(stack);
	i = 0;
	max = find_max(stack);
	while (l1->value != find_min(stack))
	{
		l1 = l1->next;
		i++;
	}
	l1 = *stack;
	while (!is_sorted(stack))
	{
		if ((l1->value > l1->next->value) && l1->value != max)
			swap_single(stack, id);
		else
		{
			if (i < size / 2)
				rotate_single(stack, id);
			else
				rrotate_single(stack, id);
		}
		l1 = *stack;
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
			if (cost_compute(stack_b, find_max(stack_b)) > 0)
				rotate_single(stack_b, 'b');
			else
				rrotate_single(stack_b, 'b');
		}
		if (!is_sorted(stack_a))
			basic_stack_sort(stack_a, 'a');
		l1 = *stack_b;
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
	if (first->value < first->next->value && first->value < last->value)
		return (1);
	else
		return (0);
}

/** Returns the value of the target node in the other stack.*/
int	find_target_value(t_list **stack, int value)
{
	t_list	*current;
	int		target;
	int		max;
	int		max_current;

	current = *stack;
	max = find_max(stack);
	if (value > max)
		return (find_min(stack));
	max_current = max;
	while (current != NULL)
	{
		if (max_current > max)
			return (find_min(stack));
		if (current->value > value && current->value < target)
			target = current->value;
		current = current->next;
	}
	return (target);
}
