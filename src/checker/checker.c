#include "get_next_line.h"

int	is_valid_move(char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	return (0);
}

void	input_move(char ***buf)
{
	int	i;	

	i = 0;
	*buf[i] = get_next_line(0);
	while (*buf[i] != 0)
	{
		*buf[i] = get_next_line(0);
		if (is_valid_move(*buf[i]) == 0)
		{
			printf("Error\n");
			free(*buf[i]);
			*buf[i] = 0;
			i = 0;
			while (*buf[i] != 0)
			{
				free(*buf[i]);
				i++;
			}
			return ;
		}
		i++;
		*buf[i] = get_next_line(0);
	}
	return ;
}
