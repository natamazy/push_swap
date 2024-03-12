/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:01:32 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/22 17:09:04 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_and_stack(char **numbers, t_stack *a_sf)
{
	int	j;

	j = 0;
	while (numbers[j] != NULL)
		free(numbers[j++]);
	free(numbers);
	while (a_sf->start->next)
		ft_lstclear(&a_sf->start->next);
	free(a_sf);
}

void	free_stack(t_stack *a_sf, t_stack *b_sf, t_list *node)
{
	while (a_sf->start)
		ft_lstclear(&a_sf->start);
	free(a_sf);
	free(b_sf);
	free(node);
	a_sf = NULL;
	b_sf = NULL;
	node = NULL;
}

void	free_split(char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j] != NULL)
	{
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

void	free_sf(t_stack *sf)
{
	sf->start = NULL;
	sf->finish = NULL;
	sf = NULL;
}

void	go_to_next(t_stack *sf, t_list *node)
{
	sf->finish = sf->start;
	sf->start = node->next;
	node->next->prev = NULL;
}
