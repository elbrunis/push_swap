#include "push_swap.h"

// check al the digits are ok
static int is_digit(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] == '-' || str[i] == '+') && sign == 0)
		{
			sign = 1;
			i++;
		}
		if (!str[i])
			return (0);
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	while(i < argc)
	{
		str = ft_strdup(argv[i++]);
		if (!str)
			ft_error("memory null", NULL, NULL);
		if(is_digit(str))
			ft_error("invalid input", NULL, NULL);
		free(str);
	}
	
	return (0);
}