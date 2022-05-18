/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:48:33 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:27:37 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);
int	ft_isdigit(int c);

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
