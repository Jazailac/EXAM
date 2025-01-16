
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char get_char(char c)
{
    if (c == 'z')
        c = 'm';
    else if (c == 'Z')
        c = 'M';
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
        c = c + 13;
    else if((c > 'm' && c < 'z') || (c > 'M' && c < 'Z'))
        c = c - 13;
    return c;
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            av[1][i] = get_char(av[1][i]);
            ft_putchar(av[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
}