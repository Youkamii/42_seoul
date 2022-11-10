/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arrayset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:18:43 by chyeok            #+#    #+#             */
/*   Updated: 2022/11/10 20:36:50 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	split_str_count(char **split_str)
{
	int	index;

	index = 0;
	while (split_str[index])
		index++;
	return (index);
}

void	free_all(char **split_strs)
{
	int	index;

	index = 0;
	while (split_strs[index])
	{
		free(split_strs[index]);
		index++;
	}
	free(split_strs);
}

int	special_atoi(const char *str)
{
	long long	result;
	int			np;
	int			chker;

	result = 0;
	np = 1;
	chker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		np = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		chker++;
	}
	result = result * np;
	if (*str != '\0' || chker > 10
		|| result > 2147483647 || result < -2147483648)
		throw_error(1);
	return ((int)result);
}

void	split_str_to_int(int *int_array, int *arr_index, char **split_strs)
{
	int	temp_number;
	int	index;

	index = 0;
	while (split_strs[index])
	{
		temp_number = special_atoi(split_strs[index]);
		int_array[*arr_index] = temp_number;
		(*arr_index)++;
		index++;
	}
}
