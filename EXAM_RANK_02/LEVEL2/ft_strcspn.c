#include <unistd.h>


int check_charset(const char *reject, char c)
{
    int i = 0;

    while (reject[i])
    {
        if (c == reject[i])
            return (0);
        i++;
    }
    return (1);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;

    while (s[i] && check_charset(reject, s[i]) && reject[i])
        i++;
    return (i);
}