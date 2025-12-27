#include "push_swap.h"

void sa(t_stack **stack_a)
{
    int first;
    int second;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    (*stack_a)->value = second;
    (*stack_a)->next->value = first;
    ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
    int first;
    int second;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    first = (*stack_b)->value;
    second = (*stack_b)->next->value;
    (*stack_b)->value = second;
    (*stack_b)->next->value = first;
    ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
    ft_printf("ss\n");
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    int value;

    if (stack_is_empty(*stack_b))
        return ;
    value = stack_pop(stack_b);
    stack_push(stack_a, value);
    ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    int value;

    if (stack_is_empty(*stack_a))
        return ;
    value = stack_pop(stack_a);
    stack_push(stack_b, value);
    ft_printf("pb\n");
}
void ra(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;

    if (stack_is_empty(*stack_a) || !(*stack_a)->next)
        return ;
    first = *stack_a;
    *stack_a = (*stack_a)->next;
    first->next = NULL;
    last = *stack_a;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *last;

    if (stack_is_empty(*stack_b) || !(*stack_b)->next)
        return ;
    first = *stack_b;
    *stack_b = (*stack_b)->next;
    first->next = NULL;
    last = *stack_b;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    ft_printf("rr\n");
}

void rra(t_stack **stack_a)
{
    t_stack *prev;
    t_stack *last;

    if (stack_is_empty(*stack_a) || !(*stack_a)->next)
        return ;
    prev = NULL;
    last = *stack_a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    t_stack *prev;
    t_stack *last;

    if (stack_is_empty(*stack_b) || !(*stack_b)->next)
        return ;
    prev = NULL;
    last = *stack_b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    ft_printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
}