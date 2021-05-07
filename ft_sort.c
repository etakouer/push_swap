/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:13:03 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/05 15:15:41 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_pushb(t_stack *stack, t_option *opt)
{
	while ((opt->code == NONE && opt->asize > 2) || \
			(opt->code == LAST && opt->asize > MINA))
	{
		opt->nbpiv[opt->ipiv] = 0;
		opt->piv.nb = ft_get_pivot(stack->a, opt->asize, opt->aipiv);
		while (((opt->code == NONE && opt->asize > 2) || \
			(opt->code == LAST && opt->asize > MINA)) && \
				ft_lower_exist(stack->a, &opt->piv, opt->aipiv))
		{
			ft_push_lower(stack, opt, &opt->num, &opt->piv);
			opt->asize--;
			opt->nbpiv[opt->ipiv]++;
			opt->bsize++;
		}
		opt->ipiv++;
	}
	if (opt->asize <= MINA && opt->code == LAST)
		ft_sort_last_asc(stack, opt, &opt->num);
	while (opt->code == NONE && \
			((t_content *)ft_lstlast(stack->a)->content)->ipiv == opt->aipiv)
		ft_execute("rra", stack, opt, ++(opt->num));
	if (opt->code == NONE && opt->asize == 2 && \
			((t_content *)stack->a->content)->ipiv == ((t_content *)stack->a->next->content)->ipiv && \
			ft_content_cmp(stack->a->content, stack->a->next->content) > 0)
		ft_execute("sa", stack, opt, ++(opt->num));
}

void	ft_pusha2(t_stack *stack, t_option *opt)
{
	while (opt->bsize > 2 && \
			((t_content *)ft_lstlast(stack->b)->content)->ipiv == opt->ipiv)
		ft_execute("rrb", stack, opt, ++opt->num);
	if (opt->nbpiv[opt->ipiv] == 2 && \
			((t_content *)stack->b->content)->ipiv == ((t_content *)stack->b->next->content)->ipiv && \
			ft_content_cmp(stack->b->content, stack->b->next->content) < 0)
		ft_execute("sb", stack, opt, ++opt->num);
	while (opt->nbpiv[opt->ipiv]-- > 0)
	{
		((t_content *)stack->b->content)->ipiv = opt->aipiv;
		ft_execute("pa", stack, opt, ++opt->num);
		opt->not_sorted++;
		opt->asize++;
		opt->bsize--;
	}
}

void	ft_pusha3(t_stack *stack, t_option *opt)
{
	opt->piv.nb = ft_get_pivot(stack->b, opt->nbpiv[opt->ipiv], opt->ipiv);
	while (opt->nbpiv[opt->ipiv] > 0 && \
			ft_greater_exist(stack->b, &opt->piv, opt->ipiv))
	{
		if (opt->nbpiv[opt->ipiv] <= SSA)
			 ft_push_greater1(stack, opt, &opt->num);
		else
			ft_push_greater(stack, opt, &opt->num, &opt->piv);
		opt->bsize--;
		opt->nbpiv[opt->ipiv]--;
		opt->asize++;
		opt->not_sorted++;
	}
	if (((t_content *)stack->a->content)->ipiv == ((t_content *)stack->a->next->content)->ipiv && \
			ft_content_cmp(stack->a->content, stack->a->next->content) > 0)
		ft_execute("sa", stack, opt, ++opt->num);
}

void	ft_pusha(t_stack *stack, t_option *opt)
{
	while (ft_stack_asc(stack->a) && opt->ipiv-- > 0 )
	{
		opt->aipiv--;
		opt->not_sorted = 0;
		while (opt->nbpiv[opt->ipiv] > 0 && ft_stack_asc(stack->a))
		{
			if (opt->nbpiv[opt->ipiv] <= 2)
				ft_pusha2(stack, opt);
			else
				ft_pusha3(stack, opt);
		}
	}
}

void	ft_sort(t_stack *stack, t_option *opt)
{
	opt->num = 0;
	if (opt->v)
		ft_stack_show(stack, opt->num, "", opt);
	opt->asize = opt->size;
	opt->nbpiv = (int [BFS]){0};
	opt->not_sorted = opt->size;
	opt->ipiv = 0;
	opt->bsize = 0;
	opt->aipiv = -1;
	while (stack->b || !ft_stack_asc(stack->a))
	{
		opt->code = LAST;
		opt->asize = opt->not_sorted;
		if (opt->asize != opt->size)
			opt->code = NONE;
		ft_pushb(stack, opt);
		ft_pusha(stack, opt);
		opt->ipiv++;
	}
	if (opt->fd > 1)
		close(opt->fd);
}
