/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:19:49 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:06:12 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"


typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

typedef struct s_pop_result
{
    int value;
    int index;
} t_pop_result;

t_stack *stack_init(int value);
t_stack *stack_init_with_index(int value, int index);
void    stack_push(t_stack **stack, int value, int index);
t_pop_result stack_pop(t_stack **stack);
int     stack_is_empty(t_stack *stack);
void    stack_free(t_stack **stack);

int     parse_args(int argc, char **argv, t_stack **stack_a);

#endif