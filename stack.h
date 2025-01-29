/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:36:19 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/13 19:01:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

void				t_stack_clear(t_stack **head);
void				t_stack_print(t_stack *head);

t_stack				*t_stack_push(t_stack **stack, int number);
t_stack				*t_stack_last(t_stack *head);
t_stack				*t_stack_pop(t_stack **head);

#endif
