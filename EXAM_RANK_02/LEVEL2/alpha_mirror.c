#include <unistd.h>


char cc(char c)
{
    char min[27] = "abcdefghijklmnopqrstuvwxyz";
    char maj[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    if (c >= 'a' && c <= 'z')
    {
        while (min[i] != c)
            i++;
        return min[25 - i];
    }
    else if (c >= 'A' && c <= 'Z')
    {
        while (maj[i] != c)
            i++;
        return maj[25 - i];
    }
    return c;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {

        int i = 0;
        while (av[1][i])
        {
            char mirrored = cc(av[1][i]);
            write(1, &mirrored, 1);
            i++;
        }
        write(1, "\n", 1);
    }
}