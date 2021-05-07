/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:46:49 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 10:47:43 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_get_maxinit(t_list **a, int ipiv, t_content **maxc, int *i)
{
	while (*a)
	{
		if (((t_content *)((*a)->content))->ipiv == ipiv)
		{
			*maxc = (*a)->content;
			return (*i);
		}
		(*i)++;
		*a = (*a)->next;
	}
	return (0);
}

int	ft_get_max(t_list *a, int *value, int ipiv)
{
	t_content	*maxc;
	int			i;
	int			pos;

	i = 0;
	pos = ft_get_maxinit(&a, ipiv, &maxc, &i);
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv && \
				ft_content_cmp(maxc, a->content) < 0)
		{
			maxc = a->content;
			pos = i;
		}
		i++;
		a = a->next;
	}
	if (value)
		*value = maxc->nb;
	return (pos);
}

int	ft_get_mininit(t_list **a, int ipiv, t_content **minc, int *i)
{
	while (*a)
	{
		if (((t_content *)((*a)->content))->ipiv == ipiv)
		{
			*minc = (*a)->content;
			return (*i);
		}
		(*i)++;
		*a = (*a)->next;
	}
	return (0);
}

int	ft_get_min(t_list *a, int *value, int ipiv)
{
	t_content	*minc;
	int			i;
	int			pos;

	i = 0;
	pos = ft_get_mininit(&a, ipiv, &minc, &i);
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv && \
				ft_content_cmp(minc, a->content) > 0)
		{
			minc = a->content;
			pos = i;
		}
		i++;
		a = a->next;
	}
	if (value)
		*value = minc->nb;
	return (pos);
}
