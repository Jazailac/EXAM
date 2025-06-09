#include <_ctype.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void skip(FILE *in)
{
    char c = fgetc(in);
    while (isspace(c) && c != EOF)
        c = fgetc(in);
    if (c != EOF)
        ungetc(c, in);
}

int pd(FILE *in, va_list ap)
{
    int *d;
    char c;
    int res = 0;;
    int sign = 1;
    int df = 0;

    skip(in);
    c = fgetc(in);
    d = va_arg(ap, int *);
    if (c == '-' || c == '+')
    {
        if (c == '-')
            sign *= -1;
        c = fgetc(in);
    }
    while (isdigit(c) && c != EOF)
    {
        res *= 10;
        res += c - '0';
        c = fgetc(in);
        df = 1;
    }
    if (df)
    {
        *d = res * sign;
        ungetc(c, in);
        return (1);
    }
    ungetc(c, in);
    return (0);
}

int ps(FILE *in, va_list ap)
{
    char c;
    char *s;
    char *h;

    skip(in);
    c = fgetc(in);
    s = va_arg(ap, char *);
    h = s;
    if (c == EOF || isspace(c))
    {
        if (c != EOF)
            ungetc(c, in);
        return (0);
    }
    while (!isspace(c) && c != EOF)
    {
        *s = c;
        c = fgetc(in);
        s++;
    }
    if (c != EOF)
        ungetc(c, in);
    *s = '\0';
    if (h < s)
        return (1);
    return (0);
}

int pc(FILE *in, va_list ap)
{
    char c;
    char *ch;

    skip(in);
    c = fgetc(in);
    ch = va_arg(ap, char *);
    if (c != EOF)
    {
        *ch = c;
        return (1);
    }
    return (0);
}

int fscan(char *str, ...)
{
    va_list ap;
    int ret  = 0;

    va_start(ap, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'd')
                ret += pd(stdin, ap);
            else if (*str == 'c')
                ret += pc(stdin, ap);
            else if (*str == 's')
                ret += ps(stdin, ap);
            str++;
        }
    }
    return (ret);
}

int main()
{
    char buffer[100];
    int result;
    char c;
    
    printf("Enter some text: ");
    result = fscan("%s", buffer);
    printf("Read: '%s', Return value: %d\n", buffer, result);

    printf("Enter a char: ");
    result = fscan("%c", &c);
    printf("Read: '%c', Return value: %d\n", c, result);
    
    
    printf("Enter a number: ");
    int num;
    result = fscan("%d", &num);
    printf("Number: %d, Return value: %d\n", num, result);
    
    return 0;
}