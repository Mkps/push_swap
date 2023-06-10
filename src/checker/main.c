#include "../../includes/ft_push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;
	int		size;
	t_list	**stack_a;
	t_list	**stack_b;

	size = elem_number(argc, argv);
	if (argc < 2)
		return (0);
	stack_a = create_stack(size);
	stack_b = create_stack(size);
	tab = import_args(argc, argv);
	if (parse_error(tab))
		return(exit_handler(argc, stack_a, stack_b, tab));
	init_stack(stack_a, stack_b, tab);
  if (is_sorted(stack_a) && *stack_b == NULL)
    output_OK(1);
  else
    output_OK(0);
	if (!exit_handler(argc, stack_a, stack_b, tab))
		return (1);
	return (0);
}
