/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:02:36 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/26 16:49:01 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero_indexing(t_stack *sf)
{
	t_list	*tmp;

	if (!sf)
		return ;
	tmp = sf->start;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
}

void	indexing(t_stack *sf)
{
	t_list	*tmp;
	t_list	*rolling_tmp;

	if (!sf)
		return ;
	zero_indexing(sf);
	tmp = sf->start;
	while (tmp)
	{
		rolling_tmp = sf->start;
		while (rolling_tmp)
		{
			if (tmp->nbr > rolling_tmp->nbr)
				tmp->index += 1;
			rolling_tmp = rolling_tmp->next;
		}
		tmp = tmp->next;
	}
}
