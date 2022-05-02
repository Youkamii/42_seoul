char    *ft_strchr(const char *str, int c)
{
    if (!(*str))
        return (0);
    else if (c == '\0')
        return ((char *)str);
    while (*str)
    {
        if(*str == c)
            return ((char *)str);
        ++str;
    }
    return (0);
}