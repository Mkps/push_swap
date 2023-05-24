#include "ft_push_swap.h"

void	sort_main(t_list **stack_a, t_list **stack_b)
{
	divide_stack(stack_a, stack_b);
	basic_stack_sort(stack_a, 'a');
	basic_stack_sort_d(stack_a, stack_b);
}
