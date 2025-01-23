#include <unistd.h>

int free_doubles(char *str, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if (str[i] == str[pos])
            return (1);
        i++;
    }
    return (0);
}

int check_f_str(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
int main(int argc, char **argv)
{
    int i;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        if (!free_doubles(argv[1], i))
            write(1, &argv[1][i], 1);
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (!free_doubles(argv[2], i) && !check_f_str(argv[1], argv[2][i]))
            write(1, &argv[2][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
