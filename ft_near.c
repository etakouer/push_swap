/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_near.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:48:44 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 10:49:27 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_near_min(t_list **a, t_content *piv, int ipiv, int *i)
{
	while (*a)
	{
		if (((t_content *)(*a)->content)->ipiv == ipiv \
				&& ft_content_cmp(piv, (*a)->content) > 0)
		{
			return (*i);
		}
		(*i)++;
		*a = (*a)->next;
	}
	return (0);
}

int	ft_get_near(t_list *a, t_content *piv, int ipiv)
{
	int	i;
	int	min;
	int	max;
	int	size;

	size = ft_lstsize(a);
	max = 0;
	i = 0;
	min = ft_get_near_min(&a, piv, ipiv, &i);
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv && \
				ft_content_cmp(piv, a->content) > 0)
			max = i;
		i++;
		a = a->next;
	}
	if (size - max < min)
		return (max);
	return (min);
}

int	ft_get_near_mini1(t_list **a, t_content *piv, int ipiv, int *i)
{
	while (*a)
	{
		if (((t_content *)(*a)->content)->ipiv == ipiv \
				&& ft_content_cmp(piv, (*a)->content) < 0)
		{
			return (*i);
		}
		(*i)++;
		*a = (*a)->next;
	}
	return (0);
}

int	ft_get_near1(t_list *a, t_content *piv, int ipiv)
{
	int	i;
	int	min;
	int	max;
	int	size;

	size = ft_lstsize(a);
	max = 0;
	i = 0;
	min = ft_get_near_mini1(&a, piv, ipiv, &i);
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv && \
				ft_content_cmp(piv, a->content) < 0)
			max = i;
		i++;
		a = a->next;
	}
	if (size - max < min)
		return (max);
	return (min);
}
