#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 4)
    {
        while (av[1][i] && (ft_strlen(av[2]) == 1) && (ft_strlen(av[3]) == 1))
        {
            if (av[1][i] == av[2][0])
                av[1][i] = av[3][0];
            i++;
        }
        ft_putstr(av[1]);
    }
    write(1, "\n", 1);
}