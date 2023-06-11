#include "../../includes/ft_push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		size;
	t_list	**stack_a;
	t_list	**stack_b;
  char    **move_list;

	size = elem_number(argc, argv);
	if (argc < 2)
		return (0);
	stack_a = create_stack(size);
	stack_b = create_stack(size);
	tab = import_args(argc, argv);
	if (parse_error(tab))
		return(exit_handler(argc, stack_a, stack_b, tab));
	init_stack(stack_a, stack_b, tab);
  input_move(&move_list);
  exec_move(&move_list);
  if (is_sorted(stack_a) && *stack_b == NULL)
    output_OK(1);
  else
    output_OK(0);
	if (!exit_handler(argc, stack_a, stack_b, tab))
		return (1);
	return (0);
}

void  input_move(t_list **move_list)
{
  while (1)
    return ;
}

void  exec_move(char ***buf, t_list **stack_a, t_list **stack_b)
{
  int i;

  i = 0;
  while (*char[i])
  {
	if (strcmp(str, "pa\n") == 0)
    	push(stack_a, stack_b, 'a');
  	if (strcmp(str, "pb\n") == 0)
    	push(stack_b, stack_a, 'b');
  	if (strcmp(str, "ra\n") == 0)
    	rotate_single(stack_a, 'a');
  	if (strcmp(str, "rb\n") == 0)
    	rotate_single(stack_b, 'b');
  	if (strcmp(str, "rr\n") == 0)
    	rotate_both(stack_a, stack_b);
  	if (strcmp(str, "rra\n") == 0)
    	rrotate_single(stack_a, 'a');
  	if (strcmp(str, "rrb\n") == 0)
    	rrotate_single(stack_b, 'b');
  	if (strcmp(str, "rrr\n") == 0)
    	rrotate_both(stack_a, stack_b);
  	if (strcmp(str, "sa\n") == 0)
    	swap_single(stack_a, 'a');
  	if (strcmp(str, "sb\n") == 0)
    	swap_single(stack_b, 'b');
  	if (strcmp(str, "ss\n") == 0)
    	swap_both(stack_a, stack_b);
	free(*char[i]);
	i++;
  }
}
