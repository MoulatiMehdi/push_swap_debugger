/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:30 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/13 18:59:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
 * Shift up all elements of `stack` by 1.The first element becomes the last one.
 * */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = t_stack_last(*stack);
	last->next = first;
}

void	ra(t_game *game)
{
	if (game == NULL)
		return ;
	rotate(&game->a);
}

void	rb(t_game *game)
{
	if (game == NULL)
		return ;
	rotate(&game->b);
}

void	rr(t_game *game)
{
	if (game == NULL)
		return ;
	ra(game);
	rb(game);
}
