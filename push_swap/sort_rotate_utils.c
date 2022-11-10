/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:24 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:35:50 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_stack_min(t_num *top)
{
	int	ret;

	ret = top->content;
	while (top)
	{
		if (ret > top->content)
			ret = top->content;
		top = top->next;
	}
	return (ret);
}

int	get_stack_max(t_num *stack)
{
	int	ret;

	ret = stack->content;
	while (stack)
	{
		if (ret < stack->content)
			ret = stack->content;
		stack = stack->next;
	}
	return (ret);
}

int	set_a_location_min(t_stack *stack)
{
	int				ret;
	int				index;
	int				temp;
	t_num			*num_a;

	ret = 0;
	temp = 0;
	num_a = stack->a_top;
	index = get_stack_min(num_a);
	while (num_a)
	{
		temp = num_a->content;
		if (temp == index)
			break ;
		ret++;
		num_a = num_a->next;
	}
	if (ret >= (stack->a_size + 1) / 2)
		ret = (stack->a_size - ret) * -1;
	return (ret);
}

int	set_a_location_max(t_stack *stack)
{
	int				ret;
	int				index;
	int				temp;
	t_num			*num_a;

	ret = 0;
	temp = 0;
	num_a = stack->a_top;
	index = get_stack_max(num_a);
	while (num_a)
	{
		temp = num_a->content;
		if (temp == index)
			break ;
		ret++;
		num_a = num_a->next;
	}
	ret++;
	if (ret >= (stack->a_size + 1) / 2)
		ret = (stack->a_size - ret) * -1;
	return (ret);
}

int	set_a_location_mid(int num, t_stack *stack)
{
	t_num	*num_a;
	int		ret;

	num_a = stack->a_top;
	ret = 1;
	while (num_a->next)
	{
		if (num > num_a->content && num < num_a->next->content)
			break ;
		ret++;
		num_a = num_a->next;
	}
	if (ret >= (stack->a_size + 1) / 2)
		ret = (stack->a_size - ret) * -1;
	return (ret);
}
