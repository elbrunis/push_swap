#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;
// crea una lista
void				create_list(t_list **list, int argc, char **argv);
// utils para borrar
void				print_list(t_list *list);

#endif