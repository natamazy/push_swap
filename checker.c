/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:18:40 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/27 17:18:41 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

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

int	doing_moves(t_stack *a_sf, t_stack *b_sf, int final)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (cmd[0] == 's')
			final += swap_check_do(cmd, a_sf, b_sf);
		else if (cmd[0] == 'r' && cmd[1] == 'r'
			&& (cmd[2] == 'a' || cmd[2] == 'b' || cmd[2] == 'r'))
			final += rev_rotate_check_do(cmd, a_sf, b_sf);
		else if (cmd[0] == 'r')
			final += rotate_check_do(cmd, a_sf, b_sf);
		else if (cmd[0] == 'p')
			final += push_check_do(cmd, a_sf, b_sf);
		else
			final += 1;
		free(cmd);
		if (final > 0)
			break ;
		cmd = get_next_line(0);
	}
	if (final > 0)
		return (1);
	return (0);
}

void	just_norm_func(t_stack *a_sf, t_stack *b_sf, t_list *node)
{
	b_sf->start = NULL;
	b_sf->finish = NULL;
	a_sf->start = node;
}

int	ft_putstr_int(char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return (1);
	}
	write(fd, s, ft_strlen(s));
	return (1);
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
	just_norm_func(a_sf, b_sf, node);
	if (!node || !a_sf || !b_sf)
		return (print_error("Error\n"));
	if (validating_all_together(argc, argv, a_sf, node) == 1)
	{
		free_stack(a_sf, b_sf, NULL);
		return (1);
	}
	if (doing_moves(a_sf, b_sf, 0) == 1)
		return (ft_putstr_int("Error\n", 2));
	if (b_sf->start == NULL && is_stack_sorted(a_sf) == 1)
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
	ft_lstclear(&b_sf->start);
	free_stack(a_sf, b_sf, node);
	return (0);
}
