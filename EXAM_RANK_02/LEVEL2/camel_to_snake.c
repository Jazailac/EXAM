#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int count_cap(char *str) {
    int i = 0;
    int count = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            count++;
        i++;
    }
    return count;
}

char *process_str(char *str) {
    char *re_str;
    int i = 0, j = 0;
    int strlen = fstrlen(str);
    int cap_count = count_cap(str);
    
    re_str = malloc(sizeof(char) * (strlen + cap_count + 1));
    if (!re_str)
        return NULL;

    while (str[i]) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            re_str[j++] = str[i];
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            re_str[j++] = '_';
            re_str[j++] = (str[i] + 32); 
        }
        i++;
    }
    re_str[j] = '\0'; 
    return re_str;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        char *processed_str = process_str(str);
        
        if (!processed_str) {
            write(1, "\n", 1);
            return 1;
        }        
        write(1, processed_str, fstrlen(processed_str)); 
        free(processed_str); 
    }
    write(1, "\n", 1);
    return 0;
}
