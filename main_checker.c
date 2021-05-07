/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:22:38 by etakouer          #+#    #+#             */
/*   Updated: 2021/05/07 10:52:15 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	t_gnl		gnl;
	t_stack		stack;
	t_list		*inst;
	t_option	opt;

	opt.ac = ac;
	opt.av = av;
	opt.prgm = 'c';
	ft_init(&opt, &gnl, &stack, &inst);
	while (1)
	{
		gnl.ret = ft_get_line(opt.fd, &gnl.line);
		if (gnl.ret < 0 || !ft_inst_add(&inst, &gnl))
			ft_err_exit(&gnl, &stack, &inst);
		if (gnl.ret == 0)
		{
			if (!ft_inst_exec(&stack, inst, &opt))
				ft_err_exit(&gnl, &stack, &inst);
			ft_check_sort(&stack, &opt);
			ft_free(&gnl, &stack, &inst);
			break ;
		}
	}
	return (0);
}
