#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_pustr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac > 2)
    {
        ft_pustr(av[1]);
    }
    ft_putchar('\n');
}