/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:14:33 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 15:15:20 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_greater_exist(t_list *b, void *piv, int ipiv)
{
	while (b)
	{
		if (((t_content *)b->content)->ipiv == ipiv && \
				ft_content_cmp(piv, b->content) < 0)
			return (1);
		b = b->next;
	}
	return (0);
}

void	ft_push_greater1(t_stack *stack, t_option *opt, int *num)
{
	int			size;
	int			pos;
	t_content	max;

	size = ft_lstsize(stack->b);
	pos = ft_get_max(stack->b, &max.nb, opt->ipiv);
	if (pos == 1)
		ft_execute("sb", stack, opt, ++(*num));
	else
	{
		if (pos == size - 1 || pos > size / 2)
			while (ft_content_cmp(&max, stack->b->content) != 0)
				ft_execute("rrb", stack, opt, ++(*num));
		else
			while (ft_content_cmp(&max, stack->b->content) != 0)
				ft_execute("rb", stack, opt, ++(*num));
	}
	((t_content *)stack->b->content)->ipiv = opt->aipiv;
	ft_execute("pa", stack, opt, ++(*num));
}

void	ft_push_greater(t_stack *stack, t_option *opt, int *num, t_content *piv)
{
	int	size;
	int	pos;

	size = ft_lstsize(stack->b);
	pos = ft_get_near1(stack->b, piv, opt->ipiv);
	if (pos == 1)
		ft_execute("sb", stack, opt, ++(*num));
	else
	{
		if (pos == size - 1 || pos > size / 2)
			while (((t_content *)stack->b->content)->ipiv != opt->ipiv || \
					ft_content_cmp(piv, stack->b->content) >= 0)
				ft_execute("rrb", stack, opt, ++(*num));
		else
			while (((t_content *)stack->b->content)->ipiv != opt->ipiv || \
					ft_content_cmp(piv, stack->b->content) >= 0)
				ft_execute("rb", stack, opt, ++(*num));
	}
	((t_content *)stack->b->content)->ipiv = opt->aipiv;
	ft_execute("pa", stack, opt, ++(*num));
}
