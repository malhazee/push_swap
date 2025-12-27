/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-haze <musab.alhazeem@learner.42.tec    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:32:32 by mal-haze          #+#    #+#             */
/*   Updated: 2025/12/27 12:10:56 by mal-haze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "push_swap.h"


int parse_args(int argc, char **argv, t_stack **stack_a);


int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    int ok;

    ok = parse_args(argc, argv, &stack_a);
    if (ok)
        printf("Accepted\n");
    else
        printf("Rejected\n");
    stack_free(&stack_a);
    return (ok ? 0 : 1);
}