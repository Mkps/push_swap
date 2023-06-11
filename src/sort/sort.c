#include "ft_push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b);
void	push_index(t_list **stack_a, t_list **stack_b);

/** Handler for the sorting functions. */
void	sort_main(t_list **stack_a, t_list **stack_b)
{
	// push(stack_a, stack_b, 'a');
	// sort_stack_a(stack_b, stack_a);
	divide_stack(stack_a, stack_b);
	// push_index(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	// basic_stack_sort_d(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	basic_stack_sort(stack_a, 'a');
	// 	output_stack(stack_a);
	// output_stack(stack_b);

}

void	push_index(t_list **stack_a, t_list **stack_b)
{
	t_list *current;
	int i_start;
	int	i_ind;
	int	i_max;
	int	i;

	i = 0;
	i_max = 0;
	current = *stack_a;
	i_start = current->value;
	i_ind = i_start;
	while (current->next != NULL)
	{
		if (i > i_max)
		{
			i_max = i;
			i_ind = i_start;
		}
		if (current->next->value < current->value)
		{
			i = 0;
			i_start = current->next->value;
		}
		i++;
		current = current->next;
	}
	// printf("i_max %i i_ind %i\n", i_max, i_ind);
	current = *stack_a;
	while (current->value != i_ind)
	{
		// printf("cd %i\n", current->value);
		push(stack_a, stack_b, 'a');
		current = *stack_a;
	}
	while (current->next->value > current->value)
	{
		rotate_single(stack_a, 'a');
		current = *stack_a;
	}
	if (current->next->value < current->value)
		rotate_single(stack_a, 'a');
	current = *stack_a;
	while (current->value != i_ind)
	{
		push(stack_a, stack_b, 'a');
		current = *stack_a;
	}
		

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
	int		val;

	node_b = *stack_b;
	cost_a = 10000;
	cost_b = 10000;
	val = INT_MIN;
	while(node_b !=NULL)
	{
		// printf("YESYES\n");
		while (node_b != NULL)
		{
			tmp_b = cost_compute(stack_b, node_b->value);
			tmp_a = cost_compute(stack_a, find_target_value(stack_a, node_b->value));
			// printf("DEBUG: node value:%i target:%i\n", node_b->value, find_target_value(stack_a, node_b->value));
			// printf("DEBUG tmp %i cost %i \n", ft_abs(tmp_a) + ft_abs(tmp_b), ft_abs(cost_a) + ft_abs(cost_b));
			if (ft_abs(tmp_a) + ft_abs(tmp_b) < ft_abs(cost_a) + ft_abs(cost_b) || (ft_abs(tmp_a) + ft_abs(tmp_b) + (val - node_b->value) <= ft_abs(cost_a) + ft_abs(cost_b) && node_b->value > val))
			{
				if (val > node_b->value)
					val = node_b->value;
				cost_a = tmp_a;
				cost_b = tmp_b;
			}
			node_b = node_b->next;
		}
		while (cost_a || cost_b){
		// printf("DEbUG cost_a: %i cost_b: %i", cost_a, cost_b);
		if (cost_a > 0 && cost_b > 0)
		{
			rotate_both(stack_a, stack_b, 'r');
			cost_a--;
			cost_b--;
		}
		if (cost_a > 0)
		{
			rotate_single(stack_a, 'a');
			cost_a--;
		}
		if (cost_b > 0)
		{
			rotate_single(stack_b, 'b');
			cost_b--;
		}
		if (cost_a < 0 && cost_b < 0)
		{
			rrotate_both(stack_a, stack_b, 'r');
			cost_a++;
			cost_b++;
		}
		if (cost_a < 0)
		{
			rrotate_single(stack_a, 'a');
			cost_a++;
		}
		if (cost_b < 0)
		{
			rrotate_single(stack_b, 'b');
			cost_b++;
		}
	}
		push(stack_b, stack_a, 'b');
		cost_a = 10000;
		cost_b = 10000;
		node_b = *stack_b;
	}

}
