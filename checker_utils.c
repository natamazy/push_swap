/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:45:40 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/27 18:45:42 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_check_do(char *command, t_stack *a_sf, t_stack *b_sf)
{
	if (command[1] == 'a' && command[2] == '\n')
	{
		sa(a_sf, 0);
		return (0);
	}
	else if (command[1] == 'b' && command[2] == '\n')
	{
		sb(b_sf, 0);
		return (0);
	}
	else if (command[1] == 's' && command[2] == '\n')
	{
		ss(a_sf, b_sf, 0);
		return (0);
	}
	else
		return (1);
}

int	push_check_do(char *command, t_stack *a_sf, t_stack *b_sf)
{
	if (command[1] == 'a' && command[2] == '\n')
	{
		pa(a_sf, b_sf, 0);
		return (0);
	}
	else if (command[1] == 'b' && command[2] == '\n')
	{
		pb(a_sf, b_sf, 0);
		return (0);
	}
	else
		return (1);
}

int	rotate_check_do(char *command, t_stack *a_sf, t_stack *b_sf)
{
	if (command[1] == 'a' && command[2] == '\n')
	{
		ra(a_sf, 0);
		return (0);
	}
	else if (command[1] == 'b' && command[2] == '\n')
	{
		rb(b_sf, 0);
		return (0);
	}
	else if (command[1] == 'r' && command[2] == '\n')
	{
		rr(a_sf, b_sf, 0);
		return (0);
	}
	else
		return (1);
}

int	rev_rotate_check_do(char *command, t_stack *a_sf, t_stack *b_sf)
{
	if (command[2] == 'a' && command[3] == '\n')
	{
		rra(a_sf, 0);
		return (0);
	}
	else if (command[2] == 'b' && command[3] == '\n')
	{
		rrb(b_sf, 0);
		return (0);
	}
	else if (command[2] == 'r' && command[3] == '\n')
	{
		rrr(a_sf, b_sf, 0);
		return (0);
	}
	else
		return (1);
}
