#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define S 1024

int check(char *str, char *av1)
{
    int i = 0;

    while (str[i] && av1[i])
    {
        if (str[i] != av1[i])
            return (0);
        i++;
    }
    return (1);
}

void replace(char *str, int len)
{
    int i = 0;
    
    while (i < len)
    {
        str[i] = '*';
        i++;
    }
}

void filter(char *str, char *av1)
{
    int i = 0;

    int len = strlen(av1);

    while (str[i])
    {
        if (check(&str[i], av1))
        {
            replace(&str[i], len);
            i += len - 1;
        }
        i++;
    }
}


int main(int ac, char **av)
{
    if (ac != 2)
        return (printf("enter a string please\n"));
    
    char *str;
    int br = 0;

    str = malloc(S);
    while (1)
    {
        br = read(0, str, S);
        if (br <= 0)
        {
            if (br < 0)
                return (printf("read error"));
            break;
        }
        str = realloc(str, br + 1);
        if (!str)
            return (printf("malloc error"));
        *(str + br) = '\0';
        filter(str, av[1]);
        write(1, str, br);
    }
    free(str);
    return (0);
}
