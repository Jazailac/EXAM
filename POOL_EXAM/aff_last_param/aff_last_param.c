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
    int idx;
    int arg_index;

    arg_index = ac -1;
    idx = 0;
    if (ac >= 2)
    {
        ft_pustr(&av[arg_index][idx]);
    }
    ft_putchar('\n');
}
