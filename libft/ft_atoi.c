int ft_atoi(const char *str)
{
    int i;
    int sign;

    i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
        i = i * 10 + (*str - '0');
        if (sign == -1 && i > 2147483648)
            return (0);
        if (sign == 1 && i > 2147483647)
            return (-1);
		str++;
	}
	return (i * sign);
}