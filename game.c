/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 15:30:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

static int	t_stack_exist(t_stack *head, int num)
{
	while (head != NULL)
	{
		if (head->num == num)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_atoi(char **str, t_state *state)
{
	long	res;
	int		sign;
	int		c;

	sign = 1;
	res = 0;
	while (**str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
		if (*(*str)++ == '-')
			sign = -1;
	if (**str < '0' || **str > '9')
		return (*state = ERR_NUMBER_FORMAT);
	while (**str >= '0' && **str <= '9')
	{
		c = **str - '0';
		res = 10 * res + c;
		if (res > 2147483647L + (sign == -1))
			return (*state = ERR_NUMBER_TOO_LARGE);
		(*str)++;
	}
	while (**str == 32)
		(*str)++;
	return (res * sign);
}

void	t_game_clear(t_game **game)
{
	if (game == NULL)
		return ;
	if (*game != NULL)
	{
		t_stack_clear(&(*game)->a);
		t_stack_clear(&(*game)->b);
	}
	free(*game);
	*game = NULL;
}

void	t_game_parse(t_game **game, char *str)
{
	t_state	state;
	int		num;

	state = OK;
	if (*str == '\0')
		state = ERR_NUMBER_FORMAT;
	while (*str)
	{
		num = ft_atoi(&str, &state);
		if (state != OK)
			break ;
		if (t_stack_exist((*game)->a, num))
			state = ERR_NUMBER_EXIST;
		if (state != OK)
			break ;
		if (t_stack_push(&(*game)->a, num) == NULL)
			state = ERR_MALLOC_FAILED;
		if (state != OK)
			break ;
	}
	if (state == OK)
		return ;
	t_game_clear(game);
	write(2, "Error\n", 6);
	exit(1);
}

t_game	*t_game_new(long argc, char **argv)
{
	t_game	*game;
	long	i;

	if (argc < 2)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	i = 1;
	game->a = NULL;
	game->b = NULL;
	game->size = argc - 1;
	while (i < argc)
	{
		t_game_parse(&game, argv[i]);
		i++;
	}
	return (game);
}
