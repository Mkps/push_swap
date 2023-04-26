/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:52:54 by aloubier          #+#    #+#             */
/*   Updated: 2023/04/26 19:28:54 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;

	if (argc < 2)
		return (0);
	tab = import_args(argc, argv);
	if (tab)
	{
		if (parse_error(tab) == 0)
			write(1, "OK", 2);
		else
			write(1, "KO", 2);
	}
	free(tab);
	return (0);
}
