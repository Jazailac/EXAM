#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int comp(char c, char *str, int index)
{
	int i;

	i = 0;
	while(i < index)
	{
		if(str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

void inter(char *s1, char *s2)
{
	int i;
	int j;
	int a;
	char arr[128] = {0};

	i = 0;
	a = 0;
	while (s1[i])
	{
		if (!comp(s1[i], s1, a))
		{
	        j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					arr[a++] = s1[i];
                    break;
				}
				j++;
			}
		}
		i++;
	}
    arr[a] = '\0';
	ft_putstr(arr);
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		if (av[1] && av[2])
		{
		    inter(av[1], av[2]);
		}
	}
	ft_putchar('\n');
}
