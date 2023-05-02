#include "ft_push_swap.h"

void    divide_stack(t_list **stack_a, t_list **stack_b)
{
    t_list	*current;
	int		nb;
	int		median;

	current = *stack_a;
	median = find_median(stack_a);
	nb = ft_lstsize(stack_a);
	nb /= 2;
	printf("DEBUG cv %i md %i", current->value, median);
    while (nb)
    {
		if(current->value < median)
		{
			push(stack_a, stack_b, 'a');
			nb--;
		}
		else
			rotate_single(stack_a, 'a');
		current = *stack_a;
    }
}

void	sort_3(t_list **stack, char id)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	
	l1 = *stack;
	l2 = *stack + 1;
	l3 = *stack + 2;
	if ((l1->value > l2->value) && (l2->value > l3->value))
	{
		rotate_single(stack, id);
		swap_single(stack, id);
		return ;
	}
	if ((l1->value < l2->value) && (l2->value > l3->value))
	{
		return ;
	}
	if ((l1->value > l2->value) && (l2->value < l3->value))
		return ;

}
