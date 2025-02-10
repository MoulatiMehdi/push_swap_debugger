/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:36 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 17:07:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
 * Swap the first 2 elements at the top of the `stack` .
 * Do nothing if there is only one or no elements.
 * */
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_game *game)
{
	if (game == NULL)
		return ;
	swap(&game->a);
}

void	sb(t_game *game)
{
	if (game == NULL)
		return ;
	swap(&game->b);
}

void	ss(t_game *game)
{
	sa(game);
	sb(game);
}
