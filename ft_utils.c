/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:42:33 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:42:36 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_set_color(int color)
{
	if (color == CCH)
		return (write(FDOUT, YEL, 5));
	if (color == COK)
		return (write(FDOUT, GRN, 5));
	if (color == CKO)
		return (write(FDOUT, RED, 5));
	if (color == CINS)
		return (write(FDOUT, MAG, 5));
	if (color == CLST)
		return (write(FDOUT, BLU, 5));
	return (write(FDOUT, WHT, 5));
}

int	ft_toint(const char *str, int *nb)
{
	int				sign;
	unsigned long	num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = (num * 10) + (*str - 48);
		if ((sign < 0 && num > INTMIN) || (sign > 0 && num > INTMAX))
			return (0);
		str++;
	}
	*nb = num * sign;
	return (1);
}

void	ft_lstiter_opt(t_list *lst, void (*f)(void *, void *), void *opt)
{
	while (lst)
	{
		f(lst->content, opt);
		lst = lst->next;
	}
}
