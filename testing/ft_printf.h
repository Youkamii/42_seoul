#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_format(va_list ap, const char format);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putnbr_fd_p(unsigned long int n, int fd);
int		ft_putnbr_fd_u(unsigned int n, int fd, char *base, int base_n);
size_t	ft_strlen(const char *str);

#endif
