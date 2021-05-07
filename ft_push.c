/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:58:26 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:40:47 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_p(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
		ft_content_color((*a)->content, CCH);
	}
}

void	ft_pa(t_list **a, t_list **b)
{
	ft_p(a, b);
}

void	ft_pb(t_list **a, t_list **b)
{
	ft_p(b, a);
}
