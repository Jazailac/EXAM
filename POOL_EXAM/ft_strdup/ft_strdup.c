#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *ft_strdup(char *str)
{
    int idx;
    int lenght;
    char *duplicated;

    lenght = ft_strlen(str) + 1;
    duplicated = malloc(sizeof(char) * lenght);
    idx = 0;
    if (duplicated == NULL)
        return NULL;
    while (str[idx])
    {
        duplicated[idx] = str[idx];
        idx++;
    }
    duplicated[idx] = '\0';
    return duplicated;
}

int main()
{
    char *srt = "jalal zailachi 12345";
    char *dup = ft_strdup(srt);

    printf("%s", dup);
}