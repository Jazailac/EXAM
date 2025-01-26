#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        else 
            i++;
    }
    return (0);
}

int main()
{
    char  str1[12] = "jo";
    char  str2[12] = "jalal";

    int x = ft_strcmp(str1, str2);
    printf("%d", x);
}
