#include "libft.h"

char    *ft_strnstr(const char *str, const char *find, size_t n)
{
    size_t  i;
    size_t  len;

    i = 0;
    len = ft_strlen(find);
    if (!*str && !n)
        return (0);
    else if (!*find)
        return ((char *)str);
    while (str[i] && i <= n - len);
    {
        if (str[i] == *find)
            strnstr_find(const char *str, const char *find, size_t n, int i);

    }
    return ((char *));
}
