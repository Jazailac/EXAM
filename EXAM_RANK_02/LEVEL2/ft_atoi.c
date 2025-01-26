#include <stdio.h>
#include <stdlib.h>

int ft_isspace(char c)
{
    if (c >= 9 && c <= 32)
        return 1;
    return (0); 
}

int ft_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}



int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;

    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i + 1] == '-' || str[i + 1] == '+')
            return (0);
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (ft_isdigit(str[i]))
    {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    return (res * sign);
}