/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:00:04 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:41:41 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_r(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		ft_content_color((*lst)->content, CCH);
		tmp = (*lst)->next;
		ft_lstlast(*lst)->next = *lst;
		(*lst)->next = NULL;
		*lst = tmp;
	}
}

void	ft_ra(t_list **a)
{
	ft_r(a);
}

void	ft_rb(t_list **b)
{
	ft_r(b);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_r(a);
	ft_r(b);
}
