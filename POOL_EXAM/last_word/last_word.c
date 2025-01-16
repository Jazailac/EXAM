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

int main(int ac, char **av)
{
    int i;
    int index;

    if (ac == 2)
    {
        i = ft_strlen(av[1]);
        index = i;
        while (i >= 0 && (av[1][i] != ' ' || av[1][i] != '\t'))
        {
            i--;
        }
        while (av[index] != '\0')
        {
            write(1, &av[1][index], 1);
            index++;
        }
    }
    write(1, "\n", 1);
}