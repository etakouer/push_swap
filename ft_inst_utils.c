/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etakouer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:10:50 by etakouer          #+#    #+#             */
/*   Updated: 2021/04/08 10:40:23 by etakouer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_inst_print(void *content)
{
	ft_putstr_fd((char *)content, FDOUT);
	ft_putstr_fd(" ", FDOUT);
}

void	ft_inst_show(t_list *inst)
{
	ft_putstr_fd("Instruction -> ", FDOUT);
	ft_lstiter(inst, ft_inst_print);
	ft_putstr_fd("\n", FDOUT);
}
