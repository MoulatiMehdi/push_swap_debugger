/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:44:42 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:06:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

char			g_try[1000];
char			g_best[1000];
char			*moves[13] = {
	"",
	"sa",
	"sb",
	"ss",
	"pa",
	"pb",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr",
	NULL,
};

typedef void	(*t_func)(t_game *);

int	is_solved(t_game *game)
{
	unsigned int	count;
	t_stack			*p;

	if (game == NULL)
		return (1);
	count = 1;
	p = game->a;
	if (p == NULL)
		return (0);
	while (p->next != NULL)
	{
		if (p->num > p->next->num)
			break ;
		count++;
		p = p->next;
	}
	return (count == game->size);
}

t_func			g_func[12][2] = {
	{},        // 0
	{sa, sa},  // 1
	{sb, sb},  // 2
	{ss, ss},  // 3
	{pa, pb},  // 4
	{pb, pa},  // 5
	{ra, rra}, // 6
	{rb, rrb}, // 7
	{rr, rrr}, // 8
	{rra, ra}, // 9
	{rrb, rb}, // 10
	{rrr, rr}, // 11
};
int				g_func_size = 12;

void	print_moves(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%-3s ", moves[(int)str[i]]);
		i++;
	}
	printf("\n");
}

void	backtrack(t_game *game, unsigned int *best, unsigned int n)
{
	int	i;

	if (*best <= n)
		return ;
	if (is_solved(game))
	{
		memcpy(g_best, g_try, n + 1);
		*best = n;
		return ;
	}
	i = 1;
	while (i < g_func_size)
	{
		if (n == 0 || g_func[i][0] != g_func[(int)g_try[n - 1]][1])
		{
			if (i == 4 && game->b == NULL)
			{
				i++;
				continue ;
			}
			if (i == 5 && game->a == NULL)
			{
				i++;
				continue ;
			}
			if ((i == 6 || i == 9) && (game->a == NULL
					|| game->a->next == NULL))
			{
				i++;
				continue ;
			}
			if ((i == 7 || i == 10) && (game->b == NULL
					|| game->b->next == NULL))
			{
				i++;
				continue ;
			}
			g_func[i][0](game);
			g_try[n] = i;
			g_try[n + 1] = 0;
			backtrack(game, best, n + 1);
			g_func[i][1](game);
		}
		i++;
	}
}

void	print_all(t_game *game, unsigned int *best, unsigned int n)
{
	int	i;

	if (*best < n)
		return ;
	if (is_solved(game))
	{
		print_moves(g_try);
		return ;
	}
	i = 1;
	while (i < g_func_size)
	{
		if (n == 0 || g_func[i][0] != g_func[(int)g_try[n - 1]][1])
		{
			if (i == 4 && game->b == NULL)
			{
				i++;
				continue ;
			}
			if (i == 5 && game->a == NULL)
			{
				i++;
				continue ;
			}
			if ((i == 6 || i == 9) && (game->a == NULL
					|| game->a->next == NULL))
			{
				i++;
				continue ;
			}
			if ((i == 7 || i == 10) && (game->b == NULL
					|| game->b->next == NULL))
			{
				i++;
				continue ;
			}
			g_func[i][0](game);
			g_try[n] = i;
			g_try[n + 1] = 0;
			print_all(game, best, n + 1);
			g_func[i][1](game);
		}
		i++;
	}
}

void	try_all(t_game *game)
{
	unsigned int	best;
	int				i;

	i = 0;
	bzero(g_try, 1000);
	bzero(g_best, 1000);
	best = game->size * log(game->size) + 1;
	backtrack(game, &best, 0);
	print_all(game, &best, 0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc < 2)
		return (0);
	game = t_game_new(argc, argv);
	try_all(game);
	t_game_clear(&game);
	return (0);
}
