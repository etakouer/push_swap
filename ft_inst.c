/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:41:01 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 12:11:02 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_exec_fct(t_fcts fct, int i, t_stack *stack)
{
	if (fct.nb_params[i] == 0)
	{
		fct.ptr_type1 = fct.ptrs[i];
		fct.ptr_type1(&stack->a);
		return ;
	}
	if (fct.nb_params[i] == 1)
	{
		fct.ptr_type1 = fct.ptrs[i];
		fct.ptr_type1(&stack->b);
		return ;
	}
	if (fct.nb_params[i] == 2)
	{
		fct.ptr_type2 = fct.ptrs[i];
		fct.ptr_type2(&stack->a, &stack->b);
		return ;
	}
}

int	ft_inst_iter(t_stack *stack, t_list *inst, t_option *opt, t_fcts *fct)
{
	int	i;
	int	num;

	num = 1;
	while (inst)
	{
		i = -1;
		while (++i < NBFCT)
		{
			if (!ft_strcmp((char *)inst->content, fct->names[i]))
			{
				ft_exec_fct(*fct, i, stack);
				if (opt->v)
					ft_stack_show(stack, num++, fct->names[i], opt);
				break ;
			}
		}
		if (i == NBFCT)
			return (0);
		inst = inst->next;
	}
	return (1);
}

int	ft_inst_exec(t_stack *stack, t_list *inst, t_option *opt)
{
	t_fcts	fct;

	fct.names = (char *[NBFCT + 1]){"sa", "sb", "ss", "pa", "pb", \
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	fct.ptrs = (void *[NBFCT]){ft_sa, ft_sb, ft_ss, ft_pa, ft_pb, \
			ft_ra, ft_rb, ft_rr, ft_rra, ft_rrb, ft_rrr};
	fct.nb_params = (int [NBFCT]){0, 1, 2, 2, 2, 0, 1, 2, 0, 1, 2};
	if (0)
		ft_putstr_fd("  \n", FDOUT);
	if (opt->v)
		ft_stack_show(stack, 0, NULL, opt);
	return (ft_inst_iter(stack, inst, opt, &fct));
}

int	ft_inst_add(t_list **inst, t_gnl *gnl)
{
	t_list			*new;
	static t_list	*last;

	if (gnl->ret == 0 && *(gnl->line) == 0)
		return (1);
	new = ft_lstnew(gnl->line);
	if (new == NULL)
		return (0);
	if (*inst)
		last->next = new;
	else
		*inst = new;
	last = new;
	gnl->line = NULL;
	return (1);
}
