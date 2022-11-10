/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:19:00 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:36:58 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ra(t_stack *info)
{
	t_num	*temp;

	if (info->a_size <= 1)
		return ;
	temp = info->a_top;
	info->a_top = info->a_top->next;
	info->a_top->prev = NULL;
	info->a_bottom->next = temp;
	temp->prev = info->a_bottom;
	info->a_bottom = temp;
	info->a_bottom->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *info)
{
	t_num	*temp;

	if (info->b_size <= 1)
		return ;
	temp = info->b_top;
	info->b_top = info->b_top->next;
	info->b_top->prev = NULL;
	info->b_bottom->next = temp;
	temp->prev = info->b_bottom;
	info->b_bottom = temp;
	info->b_bottom->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *info)
{
	t_num	*temp;

	if (info->b_size <= 1 || info->a_size <= 1)
		return ;
	temp = info->a_top;
	info->a_top = info->a_top->next;
	info->a_top->prev = NULL;
	info->a_bottom->next = temp;
	temp->prev = info->a_bottom;
	info->a_bottom = temp;
	info->a_bottom->next = NULL;
	temp = info->b_top;
	info->b_top = info->b_top->next;
	info->b_top->prev = NULL;
	info->b_bottom->next = temp;
	temp->prev = info->b_bottom;
	info->b_bottom = temp;
	info->b_bottom->next = NULL;
	write(1, "rr\n", 3);
}
