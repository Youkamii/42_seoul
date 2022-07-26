/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:12:39 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/21 18:32:00 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_format_type(va_list ap, const char format);
int		ft_putchar(char c);
int		ft_strlen(const char *str);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putnbr_ptr(unsigned long int n);
int		ft_putnbr_u(unsigned int n, char *base, int base_n);
int		main(void);

#endif
