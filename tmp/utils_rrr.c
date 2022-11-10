/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:19:05 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:37:08 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_stack *info)
{
	t_num	*temp;

	if (info->a_size <= 1)
		return ;
	temp = info->a_bottom;
	info->a_bottom = info->a_bottom->prev;
	info->a_bottom->next = NULL;
	info->a_top->prev = temp;
	temp->next = info->a_top;
	info->a_top = temp;
	info->a_top->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *info)
{
	t_num	*temp;

	if (info->b_size <= 1)
		return ;
	temp = info->b_bottom;
	info->b_bottom = info->b_bottom->prev;
	info->b_bottom->next = NULL;
	info->b_top->prev = temp;
	temp->next = info->b_top;
	info->b_top = temp;
	info->b_top->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *info)
{
	t_num	*temp;

	if (info->b_size <= 1 || info->a_size <= 1)
		return ;
	temp = info->a_bottom;
	info->a_bottom = info->a_bottom->prev;
	info->a_bottom->next = NULL;
	info->a_top->prev = temp;
	temp->next = info->a_top;
	info->a_top = temp;
	info->a_top->prev = NULL;
	temp = info->b_bottom;
	info->b_bottom = info->b_bottom->prev;
	info->b_bottom->next = NULL;
	info->b_top->prev = temp;
	temp->next = info->b_top;
	info->b_top = temp;
	info->b_top->prev = NULL;
	write(1, "rrr\n", 4);
}
