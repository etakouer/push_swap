/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:31:08 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 10:58:24 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_set_options(t_option *opt)
{
	int	tmp;
	int	c;

	while (++opt->start < opt->ac && !ft_toint(opt->av[opt->start], &tmp))
	{
		c = 0;
		if (!ft_strcmp(opt->av[opt->start], "-v") && !(c++))
			opt->v = 1;
		if (!ft_strcmp(opt->av[opt->start], "-s") && !(c++))
			opt->s = 1;
		if (!ft_strcmp(opt->av[opt->start], "-c") && !(c++))
			opt->c = 1;
		if (ft_strnstr(opt->av[opt->start], "--file=", 7) && !(c++))
		{
			opt->path = &(opt->av[opt->start][7]);
			if (opt->prgm == 'c')
				opt->fd = open(opt->path, O_RDONLY);
			else
				opt->fd = open(opt->path, O_TRUNC | O_RDWR | O_CREAT, 0644);
		}
		if (c == 0)
			break ;
	}	
}

void	ft_init(t_option *opt, t_gnl *gnl, \
		t_stack *stack, t_list **inst)
{
	if (opt->ac < 2)
		exit(0);
	stack->b = NULL;
	stack->a = NULL;
	if (inst)
		*inst = NULL;
	if (gnl)
		gnl->line = NULL;
	opt->v = 0;
	opt->c = 0;
	opt->fd = 0;
	opt->s = 0;
	if (opt->prgm == 's')
		opt->fd = 1;
	opt->path = NULL;
	opt->start = 0;
	ft_set_options(opt);
	if (opt->fd < 0)
		ft_err_exit_file(opt->path);
	opt->size = ft_stack_set(&stack->a, opt->av, opt->start, opt->ac);
	if (opt->ac < 2 || !opt->size)
		ft_err_exit_args(opt->prgm);
}

void	ft_check_sort(t_stack *stack, t_option *opt)
{
	if (!stack->b && ft_stack_asc(stack->a))
	{
		if (opt->c)
			ft_set_color(COK);
		ft_putstr_fd("OK\n", FDOUT);
	}
	else
	{
		if (opt->c)
			ft_set_color(CKO);
		ft_putstr_fd("KO\n", FDOUT);
	}
}
