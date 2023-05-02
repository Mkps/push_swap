#include "ft_push_swap.h"

void    divide_stack(t_list **stack_a, t_list **stack_b)
{
    t_list	*current;
	int		nb;
	int		median;

	current = *stack_a;
	median = find_median(stack_a);
	nb = ft_lstsize(stack_a);
	if (nb % 2 == 0)
		median++;
	printf("DEBUG cv %i md %i\n", current->value, median);
    while (ft_lstsize(stack_a) > 3)
    {
		if(current->value <= median)
		{
			push(stack_a, stack_b, 'a');
			nb--;
			if (median <= find_min(stack_a))
			{
				median = find_median(stack_a);
				nb = ft_lstsize(stack_a) / 2;
				if (nb % 2 == 0)
					median++;
			}
		}
		else
		{
			if (cost_compute_a(stack_a, median) < cost_compute_d(stack_a, median))
				rotate_single(stack_a, 'a');
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
	t_list	*l2;
	int		i;
	int		max;
	
	l1 = *stack;
	l2 = *stack + 1;
	i = 0;
	max = find_max(stack);
	while (!is_sorted(stack))
	{
		if ((l1->value > l2->value) && l1->value != max)
			swap_single(stack, id);
		else
			rotate_single(stack, id);
		l1 = *stack;
		l2 = l1->next;
		i++;
		// output_stack(stack);
		// printf("\nDEBUG iteration %i\n", i);
	}
}

void	basic_stack_sort_d(t_list **stack, char id)
{
	t_list	*l1;
	t_list	*l2;
	int		min;
	
	min = find_min(stack);
	l1 = *stack;
	l2 = *stack + 1;
	while (!is_sorted_d(stack))
	{
		if ((l1->value < l2->value) && l1->value != min)
			swap_single(stack, id);
		else
			rotate_single(stack, id);
		l1 = *stack;
		l2 = l1->next;
	// output_stack(stack);
	// printf("DEBUG l1 %i l2 %i last %i\n", l1->value, l2->value, last->value);
	}
}

