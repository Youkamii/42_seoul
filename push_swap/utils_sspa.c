/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sspa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:19:12 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:37:14 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_stack *info)
{
	int	temp;

	if (info->a_size <= 1)
		return ;
	temp = info->a_top->content;
	info->a_top->content = info->a_top->next->content;
	info->a_top->next->content = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *info)
{
	int	temp;

	if (info->b_size <= 1)
		return ;
	temp = info->b_top->content;
	info->b_top->content = info->b_top->next->content;
	info->b_top->next->content = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *info)
{
	int	temp;

	if (info->a_size <= 1)
		return ;
	if (info->b_size <= 1)
		return ;
	temp = info->a_top->content;
	info->a_top->content = info->a_top->next->content;
	info->a_top->next->content = temp;
	temp = info->b_top->content;
	info->b_top->content = info->b_top->next->content;
	info->b_top->next->content = temp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *info)
{
	t_num	*temp;

	if (info->b_size <= 0)
		return ;
	temp = info->b_top;
	if (info->b_size >= 2)
	{
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
	}
	if (info->a_size == 0)
	{
		temp->next = NULL;
		info->a_top = temp;
		info->a_bottom = temp;
	}
	else
	{
		temp->next = info->a_top;
		info->a_top->prev = temp;
		info->a_top = temp;
	}
	info->a_size += 1;
	info->b_size -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *info)
{
	t_num	*temp;

	if (info->a_size <= 0)
		return ;
	temp = info->a_top;
	if (info->a_size >= 2)
	{
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
	}
	if (info->b_size == 0)
	{
		temp->next = NULL;
		info->b_top = temp;
		info->b_bottom = temp;
	}
	else
	{
		temp->next = info->b_top;
		info->b_top->prev = temp;
		info->b_top = temp;
	}
	info->b_size += 1;
	info->a_size -= 1;
	write(1, "pb\n", 3);
}
