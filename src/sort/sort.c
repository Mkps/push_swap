#include "ft_push_swap.h"

/** Hangler for the sorting functions. */
void	sort_main(t_list **stack_a, t_list **stack_b)
{
	divide_stack(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	basic_stack_sort_d(stack_a, stack_b);
	basic_stack_sort(stack_a, 'a');

}
/**Sort 3 items with the lowest amount of moves. */
void	sort_three(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*nxt;
	t_list	*last;

	current = *stack_a;
	nxt = current->next;
	last = nxt->next;

	if (current->value > nxt->value && nxt->value < last->value && current->value < last->value)
		swap_single(stack_a, 'a');
	if (current->value > nxt->value && nxt->value > last->value && current->value > last->value)
	{
		swap_single(stack_a, 'a');
		rrotate_single(stack_a, 'a');
	}
	if (current->value > nxt->value && nxt->value < last->value && current->value > last->value)
		rotate_single(stack_a, 'a');
	if (current->value < nxt->value && nxt->value > last->value && current->value < last->value)
	{
		swap_single(stack_a, 'a');
		rotate_single(stack_a, 'a');
	}
	if (current->value < nxt->value && nxt->value > last->value && current->value > last->value)
		rrotate_single(stack_a, 'a');
	if (!stack_b)
		return ;
}