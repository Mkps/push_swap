#include "ft_push_swap.h"

/** Takes in an integer and returns its' absolute value as unsigned int. */
unsigned int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	return (number * -1);
}
