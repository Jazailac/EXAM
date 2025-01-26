#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{  
    if (ac == 4)
    {
        int res = 0;

        if (av[2][0] == '+')
        {
            res = atoi(av[1]) + atoi(av[3]);
            printf("%d\n", res);
            return (1);
        }
        else if (av[2][0] == '/')
        {
            res = atoi(av[1]) / atoi(av[3]);
            printf("%d\n", res);
            return (1);
        }

        else if (av[2][0] == '-')
        {
            res = atoi(av[1]) - atoi(av[3]);
            printf("%d\n", res);
            return (1);
        }

        else if (av[2][0] == '*')
        {
            res = atoi(av[1]) * atoi(av[3]);
            printf("%d\n", res);
            return (1);
        }
        else if (av[2][0] == '%')
        {
            res = atoi(av[1]) % atoi(av[3]);
            printf("%d\n", res);
            return (1);
        }
    }
    else 
        printf("\n");

}