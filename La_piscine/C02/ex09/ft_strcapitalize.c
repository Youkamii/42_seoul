char	*ft_strcapitalize(char *str);

char	*ft_all_btos(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_first(char *str)
{
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	return (str);
}

char	*ft_fffffff(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if ((str[i - 1] >= 48 && str[i - 1] <= 57)
			|| (str[i - 1] >= 65 && str[i - 1] <= 90)
			|| (str[i - 1] >= 97 && str[i - 1] <= 122))
			i++;
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			else if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	ft_all_btos(str);
	ft_first(str);
	ft_fffffff(str);
	return (str);
}
