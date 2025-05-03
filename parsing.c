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
		if ((str[i] == '-' || str[i] == '+') && sign == 0)
		{
			sign = 1;
			i++;
		}
		if (!str[i])
			return (1);
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	return (0);
}

static int	check_int(char *str)
{
	if (ft_atol(str) != ft_atoi(str)) //vrango int min y el int max
		return (1);
	// get_max_min //funcion futura para guardar el numero maximo y el minimo
	return (0);
}

static int	check_array(char **array)
{
	int	i;

	if (!array)
		ft_error("no entro", NULL, NULL);
	i = 0;
	while (array[i]) // verificacion de el int min
	{
		if(is_digit(array[i]))
		{
			free_array(array);
			ft_error("invalid input", NULL, NULL);
		}
		if (check_int(array[i]))
		{
			free_array(array);
			ft_error("INT_MIN", NULL, NULL);
		}
		i++;
	}
	free_array(array);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**str_array;

	str_array = NULL;
	str = NULL;
	i = 1;
	while(i < argc)
	{
		str = ft_strdup(argv[i++]);// extraemos el argumento
		if (!str)
			ft_error("memory null", NULL, NULL);
		str_array = ft_split(str, ' ');
		if(!str_array[1]) // verificamos si es una string
		{
			free_array(str_array);
			if(is_digit(str))
			{
				free(str);
				ft_error("invalid input", NULL, NULL);
			}
			if (check_int(str))
			{
				free(str);
				ft_error("INT_MIN", NULL, NULL);
			}
		}
		else
			check_array(str_array);
		free(str);
	}
	
	return (0);
}
