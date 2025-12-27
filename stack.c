/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:23:36 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 11:59:05 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack *stack_init(int value)
   {
       return stack_init_with_index(value, -1);
   }

t_stack *stack_init_with_index(int value, int index)
{
    t_stack *new_node;

    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}

void   stack_push(t_stack **stack, int value, int index)
   {
       t_stack *new_node;

       new_node = stack_init_with_index(value, index);
       if (!new_node)
           return ;
       new_node->next = *stack;
       *stack = new_node;
   }

typedef struct s_pop_result
{
    int value;
    int index;
} t_pop_result;

t_pop_result stack_pop(t_stack **stack)
{
    t_pop_result result = {0, -1};
    t_stack *temp;

    if (!stack || !*stack)
        return result;
    temp = *stack;
    result.value = temp->value;
    result.index = temp->index;
    *stack = temp->next;
    free(temp);
    return result;
}
int stack_is_empty(t_stack *stack)
{
    return (stack == NULL);
}
void stack_free(t_stack **stack)
{
    t_stack *temp;
    t_stack *current;

    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
    *stack = NULL;
}