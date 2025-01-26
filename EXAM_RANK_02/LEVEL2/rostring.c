#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *find_first_word(char *str)
{
    int i = 0, j = 0;
    char *word = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!word)
        return NULL;

    // Skip leading spaces and tabs
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Extract the first word
    while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
        word[j++] = str[i++];
    word[j] = '\0';

    return word;
}

char *remove_extra_spaces(char *str)
{
    int i = 0, j = 0;
    char *cleaned = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (!cleaned)
        return NULL;

    // Skip leading spaces
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Copy characters, collapsing multiple spaces
    while (str[i])
    {
        if ((str[i] == ' ' || str[i] == '\t'))
        {
            if (j > 0 && cleaned[j - 1] != ' ')
                cleaned[j++] = ' ';
        }
        else
        {
            cleaned[j++] = str[i];
        }
        i++;
    }

    // Remove trailing space, if any
    if (j > 0 && cleaned[j - 1] == ' ')
        j--;

    cleaned[j] = '\0';
    return cleaned;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *str = av[1];
        char *word = find_first_word(str);
        char *cleaned = remove_extra_spaces(str);

        if (!word || !cleaned)
            return 1;

        // Allocate memory for the result string
        int total_len = ft_strlen(cleaned) + ft_strlen(word) + 2; // Extra space and null terminator
        char *new_str = (char *)malloc(sizeof(char) * total_len);
        if (!new_str)
            return 1;

        int j = 0, i = ft_strlen(word);

        // Copy cleaned string excluding the first word
        while (cleaned[i])
            new_str[j++] = cleaned[i++];

        // Add a space if there's remaining text
        if (j > 0)
            new_str[j++] = ' ';

        // Append the first word
        i = 0;
        while (word[i])
            new_str[j++] = word[i++];

        new_str[j] = '\0';

        printf("%s\n", new_str);

        // Free allocated memory
        free(word);
        free(cleaned);
        free(new_str);
    }
    else
    {
        write(1, "\n", 1);
    }

    return 0;
}
