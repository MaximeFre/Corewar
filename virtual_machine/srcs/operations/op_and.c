/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhojt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 23:02:33 by dhojt             #+#    #+#             */
/*   Updated: 2018/06/15 03:06:10 by dhojt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

static void			get_value(t_vm *vm, t_process *ps, unsigned char encoded,
		int *parameter)
{
	if (encoded == REG_CODE)
		*parameter = ps->r[*parameter];
	if (encoded == DIR_CODE)
		;
	if (encoded == IND_CODE)
		*parameter = vm->memory[ps->pc + *parameter];
}

void				op_and(t_vm *vm, t_process *ps)
{
	unsigned char	encoded;
	int				bytes;
	int				p1;
	int				p2;
	int				p3;

	modify_pc_tmp(ps, 1);
	encoded = vm->memory[ps->pc_tmp];
	calc_bytes(encoded, 1, &bytes);
	get_next_bytes(vm, ps, &p1, bytes);
	get_value(vm, ps, decode_byte(encoded, 1), &p1);
	calc_bytes(encoded, 2, &bytes);
	get_next_bytes(vm, ps, &p2, bytes);
	get_value(vm, ps, decode_byte(encoded, 2), &p1);
	get_next_bytes(vm, ps, &p3, 1);
	ps->r[p3] = p1 & p2;
	if (!ps->r[p3])
		ps->carry = 1;
	iterate_pc(ps);
}
