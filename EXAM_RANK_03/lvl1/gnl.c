#include <string.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define S 1024


int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return  i;
}



char *gnl(int fd)
{
    static int pos;
    char line[S];
    static char str[S];
    int i = 0;
    static int br = 0;

    while (1)
    {
        if (pos >= br)
        {
            br = read(fd, str, S);
            pos = 0;
            if (br <= 0)
                break;
        }
        line[i++] = str[pos++];
        if(str[pos - 1] == '\0' || str[pos - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (strdup(line));
}


int main(int ac, char **av)
{
    int fd = open("text.txt", O_RDWR, O_CREAT);

    char *line = gnl(fd);
    while (line)
        printf("%s", line = gnl(fd));
}
