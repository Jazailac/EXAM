#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    if (!src)
        return (NULL);

    int len = ft_strlen(src) + 1;
    char *dup;
    int i = 0;
    dup = (char *)malloc(sizeof(char) * len);

    if (!dup)  
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }   
    dup[i] = '\0';
    return (dup);
}