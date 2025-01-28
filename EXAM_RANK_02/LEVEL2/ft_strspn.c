#include <unistd.h>

int check_charset(const char *accept, char c)
{
    int i = 0;

    while (accept[i])
    {
        if (c == accept[i])
            return (0);
        i++;
    }
    return (1);
}

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;

    while (s[i] && (!check_charset(accept, s[i])) && accept[i])
        i++;
    return (i);
}