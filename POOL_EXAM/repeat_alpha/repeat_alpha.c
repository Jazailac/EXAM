#include <unistd.h>

int get_letter_count(char c)
{
    int count;

    if (c >= 'a' && c <= 'z')
        count = c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        count = c - 'A' + 1;
    else 
        return 1;
    return count;
}

int main(int ac, char **av)
{
    int i;
    int count;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i] != '\0')
        {
            count = get_letter_count(av[1][i]);
            while (count > 0)
            {
                write(1, &av[1][i], 1);
                count--;
            }
            i++;
        }
    }
    write(1, "\n",1);
}