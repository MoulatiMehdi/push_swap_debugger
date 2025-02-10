/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:48:50 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 16:09:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

#define TABLE_TAB "\t\t"
#define SEPERATOR "    |    "

typedef struct s_cmd
{
	void	(*func)(t_game *);
	char	name[10];
}			t_cmd;

void	t_game_print(t_game *head)
{
	t_stack	*p_a;
	t_stack	*p_b;

	if (head == NULL)
		return ;
	p_a = head->a;
	p_b = head->b;
	printf(TABLE_TAB "┌─────────────┬─────────────┐ \n");
	printf(TABLE_TAB "│      A      │      B      │\n");
	while (p_a != NULL || p_b != NULL)
	{
		printf(TABLE_TAB "├─────────────┼─────────────┤\n");
		printf(TABLE_TAB "│   ");
		if (p_a != NULL)
		{
			printf("%7d", p_a->num);
			p_a = p_a->next;
		}
		else
			printf("       ");
		printf("   │   ");
		if (p_b != NULL)
		{
			printf("%7d", p_b->num);
			p_b = p_b->next;
		}
		else
			printf("       ");
		printf("   │\n");
	}
	printf(TABLE_TAB "└─────────────┴─────────────┘\n");
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	str[100];
	int		found;

	setvbuf(stdout, NULL, _IONBF, 0);
	t_cmd cmds[11] = {
		{
			.func = sa,
			.name = "sa",
		},
		{
			.func = sb,
			.name = "sb",
		},
		{
			.func = pa,
			.name = "pa",
		},
		{
			.func = pb,
			.name = "pb",
		},
		{
			.func = ss,
			.name = "ss",
		},
		{
			.func = ra,
			.name = "ra",
		},
		{
			.func = rb,
			.name = "rb",
		},
		{
			.func = rra,
			.name = "rra",
		},
		{
			.func = rrb,
			.name = "rrb",
		},
		{
			.func = rrr,
			.name = "rrr",
		},
		{
			.func = rr,
			.name = "rr",
		},
	};
	if (argc < 2)
		return (0);
	game = t_game_new(argc, argv);
	t_game_print(game);
	do
	{
		found = 0;
		printf("\033[1;32m push_swap\033[0m$ ");
		scanf("%s", str);
		for (int i = 0; i < 10; i++)
		{
			if (!strcmp(str, cmds[i].name))
			{
				found = 1;
				cmds[i].func(game);
				break ;
			}
		}
		if (!found && (!strcmp(str, "restart") || !strcmp(str, "re")))
		{
			found = 1;
			t_game_clear(&game);
			game = t_game_new(argc, argv);
		}
		if (!found && (!strcmp(str, "exit") || !strcmp(str, "q")))
		{
			break ;
		}
		if (!found)
			printf("%s : command not found\n", str);
		t_game_print(game);
	} while (1);
	t_game_clear(&game);
}
