#include <unistd.h>

char addone(char c)
{
    if (c == 'z')
        return (c = 'a', c);
    if (c == 'Z')
        return (c = 'a', c);
    return (c + 1);
}


int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            av[1][i] = addone(av[1][i]);
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}