/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:26 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/13 18:53:28 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*
 * Take the first element at the top of `b` and put it at the top of `a`.
 * Do nothing if `b` is empty.
 * */
static void	push(t_stack **a, t_stack **b)
{
	t_stack	*to_push;

	if (a == NULL || b == NULL || *b == NULL)
		return ;
	to_push = *b;
	*b = to_push->next;
	to_push->next = *a;
	*a = to_push;
}

void	pa(t_game *game)
{
	if (game == NULL)
		return ;
	push(&game->a, &game->b);
}

void	pb(t_game *game)
{
	if (game == NULL)
		return ;
	push(&game->b, &game->a);
}
