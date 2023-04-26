/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:52:54 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/24 14:24:35 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

<<<<<<< HEAD
int	main(int argc,char **argv)
=======
int	main(int argc, char **argv)
>>>>>>> 17b16fc8c225969779cfac7896e5da0e0a268f45
{
	if (argc < 2)
		return (0);
	elem_number(argc, argv);
	t_list	*new;
	new = malloc(sizeof (t_list));
	new->next = 0;
	new->value = 0;
	swap_elem(new, 'a');
<<<<<<< HEAD
	//write(1, "hello", 5);
	if (argc >= 2)
	{
		if (parse_error(argv) == 0)
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
	}
=======
	write(1, "hello", 5);
>>>>>>> 17b16fc8c225969779cfac7896e5da0e0a268f45
	return (0);
}
