#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i])
	{
		while (str[i] <= 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
			{
				return (0);
			}
			else if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - 48;
			i++;
		}
		i++;
	}
	return (res * sign);
}

int main()
{
    int nb = ft_atoi("  -123abc");
    printf("%d", nb);
}