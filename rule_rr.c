/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:33 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/13 18:59:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
 * Shift down all elements of `stack` by 1.
 * The first element becomes the last one.
 * */
static void	rotate_rev(t_stack **stack)
{
	t_stack	*prev_last;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_game *game)
{
	if (game == NULL)
		return ;
	rotate_rev(&game->a);
}

void	rrb(t_game *game)
{
	if (game == NULL)
		return ;
	rotate_rev(&game->b);
}

void	rrr(t_game *game)
{
	if (game == NULL)
		return ;
	rra(game);
	rrb(game);
}
