#include "ft_push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b);

/** Hangler for the sorting functions. */
void	sort_main(t_list **stack_a, t_list **stack_b)
{
	divide_stack(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	//basic_stack_sort_d(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	//basic_stack_sort(stack_a, 'a');

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

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	int		cost_a;
	int		cost_b;
	int		tmp_a;
	int		tmp_b;

	node_b = *stack_b;
	cost_a = 0;
	cost_b = 0;
	while(node_b !=NULL)
	{
		while (node_b != NULL)
		{
			tmp_b = cost_compute(stack_b, node_b->value);
			tmp_a = cost_compute(stack_a, find_target_value(stack_a, node_b));
			if (ft_abs(tmp_a) + ft_abs(tmp_b) > ft_abs(cost_a) + ft_abs(cost_b))
			{
				cost_a = tmp_a;
				cost_b = tmp_b;
			}
			node_b = node_b->next;
		}
		while (cost_a > 0 && cost_b > 0)
		{
			rotate_both(stack_a, stack_b);
			cost_a--;
			cost_b--;
		}
		while (cost_a > 0)
		{
			rotate_single(stack_a, 'a');
			cost_a--;
		}
		while (cost_b > 0)
		{
			rotate_single(stack_b, 'b');
			cost_b--;
		}
		while (cost_a < 0 && cost_b < 0)
		{
			rrotate_both(stack_a, stack_b);
			cost_a++;
			cost_b++;
		}
		while (cost_a < 0)
		{
			rrotate_single(stack_a, 'a');
			cost_a++;
		}
		while (cost_b < 0)
		{
			rrotate_single(stack_b, 'b');
			cost_b++;
		}
		push(stack_b, stack_a, 'b');
		node_b = *stack_b;
		basic_stack_sort(stack_a, 'a');
	}

}