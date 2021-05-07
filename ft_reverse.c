/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:01:56 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:41:26 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_lstblast(t_list *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

static	void	ft_r(t_list **lst)
{
	t_list	*blast;
	t_list	*last;

	if (*lst && (*lst)->next)
	{
		blast = ft_lstblast(*lst);
		last = blast->next;
		last->next = *lst;
		blast->next = NULL;
		*lst = last;
		ft_content_color((*lst)->content, CCH);
	}
}

void	ft_rra(t_list **a)
{
	ft_r(a);
}

void	ft_rrb(t_list **b)
{
	ft_r(b);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_r(a);
	ft_r(b);
}
