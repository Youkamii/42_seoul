/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:11:07 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/17 19:11:08 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	usc_str;
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		usc_str = str[i];
		if (usc_str >= 32 && usc_str <= 126)
			write (1, &usc_str, 1);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[usc_str / 16]);
			ft_putchar("0123456789abcdef"[usc_str % 16]);
		}
		i++;
	}
}
