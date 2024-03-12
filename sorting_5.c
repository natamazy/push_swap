/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:39:12 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 18:19:43 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_5(t_stack *a_sf, t_stack *b_sf)
{
	int	i;

	i = 0;
	while (a_sf->size > 3)
	{
		if (a_sf->start->index == i)
		{
			pb(a_sf, b_sf, 1);
			i++;
		}
		else if (position_of_node_by_index(a_sf, i) > 3)
			rra(a_sf, 1);
		else
			ra(a_sf, 1);
	}
	small_sort(a_sf);
	while (b_sf->start != NULL)
		pa(a_sf, b_sf, 1);
}
