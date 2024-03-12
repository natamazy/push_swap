/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:05:53 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/23 14:20:25 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation_helper(char **nums, t_stack *sf)
{
	long long	k;
	int			j;

	j = 0;
	while (nums[j] != NULL)
	{
		k = ft_atoi(nums[j], 0, 0, 0);
		if (k >= INT_MIN && k <= INT_MAX)
		{
			sf->start->next = ft_lstnew(k, sf->start);
			sf->start = sf->start->next;
		}
		else
			return (1);
		j++;
	}
	return (0);
}

void	validation(int count, char *arguments[], t_stack *sf, t_list *node)
{
	int			i;
	int			k;
	char		**nums;

	i = 1;
	k = 0;
	while (i < count)
	{
		nums = ft_split(arguments[i], ' ');
		if (validation_helper(nums, sf) == 1)
		{
			free_split(nums);
			ft_lstclear(&node);
			free_sf(sf);
			k = 1;
			return ;
		}
		else
			free_split(nums);
		i++;
	}
	if (k == 0)
		go_to_next(sf, node);
	else
		return ;
}

int	is_everything_legit(int count, char *arguments[])
{
	int	i;
	int	j;
	int	len;

	i = 1;
	j = 0;
	len = 0;
	while (i < count)
	{
		len = ft_strlen(arguments[i]);
		while (j < len)
		{
			if (is_digit_space_sign(arguments[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicate_checker(t_stack *a_sf)
{
	t_list	*number_checked;
	t_list	*tmp;

	number_checked = a_sf->start;
	while (number_checked)
	{
		tmp = number_checked->next;
		while (tmp)
		{
			if (tmp->nbr == number_checked->nbr)
				return (1);
			tmp = tmp->next;
		}
		number_checked = number_checked->next;
	}
	return (0);
}

int	validating_all_together(int count, char *arguments[],
		t_stack *a_sf, t_list *node)
{
	if (count == 1)
		return (1);
	if (is_everything_legit(count, arguments) == 1
		|| space_checker(arguments, 0, 0) == 1)
	{
		print_error("Error\n");
		return (1);
	}
	validation(count, arguments, a_sf, node);
	if (a_sf->start == NULL && a_sf->finish == NULL)
	{
		print_error("Error\n");
		return (1);
	}
	if (duplicate_checker(a_sf) == 1)
	{
		print_error("Error\n");
		return (1);
	}
	return (0);
}
