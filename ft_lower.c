/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:10:37 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 15:13:13 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lower_exist(t_list *a, void *piv, int ipiv)
{
	while (a)
	{
		if (((t_content *)a->content)->ipiv == ipiv && \
				ft_content_cmp(piv, a->content) > 0)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_push_lower1(t_stack *stack, t_option *opt, int *num)
{
	int			pos;
	int			size;
	t_content	min;

	size = ft_lstsize(stack->a);
	pos = ft_get_min(stack->a, &(min.nb), opt->aipiv);
	if (pos == 1)
	{
		ft_execute("sa", stack, opt, ++(*num));
	}
	else
	{
		if (pos == size - 1 || pos > size / 2)
		{
			while (ft_content_cmp(&min, stack->a->content) != 0)
				ft_execute("rra", stack, opt, ++(*num));
		}
		else
		{
			while (ft_content_cmp(&min, stack->a->content) != 0)
				ft_execute("ra", stack, opt, ++(*num));
		}
	}
	((t_content *)stack->a->content)->ipiv = opt->ipiv;
	ft_execute("pb", stack, opt, ++(*num));
}

void	ft_push_lower(t_stack *stack, t_option *opt, int *num, t_content *piv)
{
	int	pos;
	int	size;

	size = ft_lstsize(stack->a);
	pos = ft_get_near(stack->a, piv, opt->aipiv);
	if (pos == 1)
		ft_execute("sa", stack, opt, ++(*num));
	else
	{
		if (pos == size - 1 || pos > size / 2)
			while (((t_content *)stack->a->content)->ipiv != opt->aipiv || \
					ft_content_cmp(piv, stack->a->content) <= 0)
				ft_execute("rra", stack, opt, ++(*num));
		else
			while (((t_content *)stack->a->content)->ipiv != opt->aipiv || \
					ft_content_cmp(piv, stack->a->content) <= 0)
				ft_execute("ra", stack, opt, ++(*num));
	}
	((t_content *)stack->a->content)->ipiv = opt->ipiv;
	ft_execute("pb", stack, opt, ++(*num));
}

void	ft_sort_last_asc(t_stack *stack, t_option *opt, int *num)
{
	int	pos;

	if (opt->ipiv > 0)
		opt->ipiv--;
	while (opt->asize > 3)
	{
		ft_push_lower1(stack, opt, num);
		opt->asize--;
		opt->bsize++;
		opt->nbpiv[opt->ipiv]++;
	}
	while (!ft_stack_asc(stack->a))
	{
		pos = ft_get_max(stack->a, NULL, opt->aipiv);
		if (pos == 0)
			ft_execute("ra", stack, opt, ++(*num));
		else
		{
			if (pos == 1)
				ft_execute("rra", stack, opt, ++(*num));
			else
				ft_execute("sa", stack, opt, ++(*num));
		}
	}
	opt->ipiv++;
}
