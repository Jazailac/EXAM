#include <unistd.h>

void ft_putnbr(int nb)
{
    char digit;
    char str[15] = "0123456789";

    if (nb >= 10)
        ft_putnbr(nb / 10);
    digit = (nb % 10) + '0';
    write(1, &digit, 1);
}

int ft_atoi(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int ft_is_prime(int nbr)
{
    int i = 3;
    if (nbr < 2)
        return (0);
    if (nbr == 2)
        return (1);
    if (nbr % 2 == 0)
        return (0);
    if (nbr < 2)
        return (0);
    while (i * i <= nbr)
    {
        if (nbr % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}

int main(int ac, char **av)
{
    int num;
    int sum = 0;
    int i;

    if (ac != 2 || !(num = ft_atoi(av[1])))
    {
        write(1, "0\n", 2);
        return (0);
    }

    i = 2;
    while (i <= num)
    {
        if (ft_is_prime(i))
            sum += i;
        i++;
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return (0);
}