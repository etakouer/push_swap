/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:54:12 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:42:50 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_s(t_list **lst)
{
	t_list	*next;

	if (*lst && (*lst)->next)
	{	
		ft_content_color((*lst)->content, CCH);
		ft_content_color((*lst)->next->content, CCH);
		next = (*lst)->next;
		(*lst)->next = next->next;
		next->next = *lst;
		*lst = next;
	}
}

void	ft_sa(t_list **a)
{
	ft_s(a);
}

void	ft_sb(t_list **b)
{
	ft_s(b);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a);
	ft_sb(b);
}
