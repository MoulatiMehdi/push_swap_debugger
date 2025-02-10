/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:35:50 by mmoulati          #+#    #+#             */
/*   Updated: 2025/01/16 15:22:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*t_stack_new(int number)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (new_elem == NULL)
		return (NULL);
	new_elem->num = number;
	new_elem->next = NULL;
	new_elem->rank = 0;
	return (new_elem);
}

t_stack	*t_stack_last(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
	{
		head = head->next;
	}
	return (head);
}

t_stack	*t_stack_push(t_stack **head, int number)
{
	t_stack	*p;
	t_stack	*new_elem;
	int		rank;

	if (head == NULL)
		return (NULL);
	new_elem = t_stack_new(number);
	if (new_elem == NULL)
		return (NULL);
	p = *head;
	if (p == NULL)
		return (*head = new_elem);
	rank = 0;
	while (p->next != NULL)
	{
		rank += (number > p->num);
		p->rank += !(number > p->num);
		p = p->next;
	}
	p->next = new_elem;
	rank += (number > p->num);
	p->rank += !(number > p->num);
	new_elem->rank = rank;
	return (new_elem);
}

t_stack	*t_stack_pop(t_stack **head)
{
	t_stack	*prev_p;
	t_stack	*p;

	if (head == NULL || *head == NULL)
		return (NULL);
	prev_p = NULL;
	p = *head;
	while (p->next != NULL)
	{
		prev_p = p;
		p = p->next;
	}
	if (prev_p == NULL)
		*head = NULL;
	else
		prev_p->next = NULL;
	return (p);
}

void	t_stack_clear(t_stack **head)
{
	t_stack	*p;

	if (head == NULL || *head == NULL)
		return ;
	p = *head;
	while (p != NULL)
	{
		*head = p->next;
		p->next = NULL;
		p->num = 0;
		free(p);
		p = *head;
	}
}
