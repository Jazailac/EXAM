#include <unistd.h>

char cc(char str)
{
        if (str >= 'a' && str <= 'm')
            return (str += 13);
        else if (str >= 'A' && str <= 'M')
            return (str += 13);
        else if (str > 'M' && str <= 'Z')
            return (str -= 13);
        else if (str > 'm' && str <= 'z')
            return (str -= 13);
        return (str);
}


int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            av[1][i] = cc(av[1][i]);
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}