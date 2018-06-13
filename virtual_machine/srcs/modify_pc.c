/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:26:09 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/12 19:19:21 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void				modify_pc(t_process *ps, int modify)
{
	if (modify > 0)
		ps->pc = (ps->pc + modify) % MEM_SIZE;
	else if (modify < 0)
		ps->pc = ((ps->pc + modify) % MEM_SIZE) + MEM_SIZE;
}