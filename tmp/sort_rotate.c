/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:15 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 23:00:34 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	set_a_location(int num, t_stack *stack)
{
	int	ret;

	if (num < get_stack_min(stack->a_top))
		ret = set_a_location_min(stack);
	else if (num > get_stack_max(stack->a_top))
		ret = set_a_location_max(stack);
	else
		ret = set_a_location_mid(num, stack);
	return (ret);
}

void	ft_rotation_same(t_stack *stack, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rr(stack);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		rrr(stack);
		(*a)++;
		(*b)++;
	}
}

void	ft_rotation_a(t_stack *stack, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stack);
			a--;
		}
		else
		{
			rra(stack);
			a++;
		}
	}
}

void	ft_rotation_b(t_stack *stack, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stack);
			b--;
		}
		else
		{
			rrb(stack);
			b++;
		}
	}
}
