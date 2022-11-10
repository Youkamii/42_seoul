/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sspa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:19:12 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 22:58:38 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_stack *info)
{
	int	tmp;

	if (info->a_size <= 1)
		return ;
	tmp = info->a_top->content;
	info->a_top->content = info->a_top->next->content;
	info->a_top->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *info)
{
	int	tmp;

	if (info->b_size <= 1)
		return ;
	tmp = info->b_top->content;
	info->b_top->content = info->b_top->next->content;
	info->b_top->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *info)
{
	int	tmp;

	if (info->a_size <= 1)
		return ;
	if (info->b_size <= 1)
		return ;
	tmp = info->a_top->content;
	info->a_top->content = info->a_top->next->content;
	info->a_top->next->content = tmp;
	tmp = info->b_top->content;
	info->b_top->content = info->b_top->next->content;
	info->b_top->next->content = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *info)
{
	t_num	*tmp;

	if (info->b_size <= 0)
		return ;
	tmp = info->b_top;
	if (info->b_size >= 2)
	{
		info->b_top = info->b_top->next;
		info->b_top->prev = NULL;
	}
	if (info->a_size == 0)
	{
		tmp->next = NULL;
		info->a_top = tmp;
		info->a_bottom = tmp;
	}
	else
	{
		tmp->next = info->a_top;
		info->a_top->prev = tmp;
		info->a_top = tmp;
	}
	info->a_size += 1;
	info->b_size -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *info)
{
	t_num	*tmp;

	if (info->a_size <= 0)
		return ;
	tmp = info->a_top;
	if (info->a_size >= 2)
	{
		info->a_top = info->a_top->next;
		info->a_top->prev = NULL;
	}
	if (info->b_size == 0)
	{
		tmp->next = NULL;
		info->b_top = tmp;
		info->b_bottom = tmp;
	}
	else
	{
		tmp->next = info->b_top;
		info->b_top->prev = tmp;
		info->b_top = tmp;
	}
	info->b_size += 1;
	info->a_size -= 1;
	write(1, "pb\n", 3);
}
