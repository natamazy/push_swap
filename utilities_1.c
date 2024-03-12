/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:17:34 by natamazy          #+#    #+#             */
/*   Updated: 2024/02/21 19:02:04 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long long nbr, t_list *prev)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	new_node->prev = prev;
	return (new_node);
}

void	ft_putstr(char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return ;
	}
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_digit_space_sign(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 9 && c <= 13)
		|| c == 32 || c == '-' || c == '+')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str, int i, int j, int flag)
{
	long long	sign;
	long long	res;

	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		flag = ++i;
	while (str[i] != '\0' && str[i] == '0')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		j++;
	}
	if (str[i] != '\0' || j > 10 || (res == 0 && (sign == -1 || flag > 0)))
		return (LONG_MAX);
	return (res * sign);
}
