/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:27:57 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 18:11:42 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	space_checker(char *argv[], int i, int j)
{
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (1);
		while (argv[i][j] == ' ')
		{
			j++;
			if (argv[i][j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a_sf;
	t_stack	*b_sf;
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	node->next = NULL;
	a_sf = (t_stack *) malloc(sizeof(t_stack));
	b_sf = (t_stack *) malloc(sizeof(t_stack));
	if (!node || !a_sf || !b_sf)
		return (print_error("Error\n"));
	b_sf->start = NULL;
	b_sf->finish = NULL;
	a_sf->start = node;
	if (validating_all_together(argc, argv, a_sf, node) == 1)
	{
		free_stack(a_sf, b_sf, NULL);
		return (1);
	}
	a_sf->size = length_of_stack(a_sf);
	indexing(a_sf);
	full_sort(a_sf, b_sf);
	free_stack(a_sf, b_sf, node);
	return (0);
}
