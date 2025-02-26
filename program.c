#include "push_swap.h"

t_list	*new_node(int argv)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = argv;
	node->next = NULL;
	return (node);
}

void	create_list(t_list *list, int argc, char **argv)
{
	t_list	*node;
	t_list	*temp;
	int		i;

	i = 1; // omite el primer arg = [./programa]
	while (i < argc)
	{
		if (list == NULL)
			new_node(ft_itoa(argv[i]));
		else
		{
			temp = list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node(ft_itoa(argv[i]));
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list *list;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	create_list(list, argc, argv);
	return (0);
}