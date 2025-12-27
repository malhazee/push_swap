#include "push_swap.h"

int  is_valid_number(const char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_duplicate(t_stack *stack, int value)
{
    t_stack *current;

    current = stack;
    while (current)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

int parse_args(int argc, char **argv, t_stack **stack_a)
{
    int i;
    long num;
    int size;

    char **args = NULL;
    int arg_count = 0;
    int ret = 1;

    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        if (!args)
            return (0);
        // احسب عدد العناصر
        while (args[arg_count])
            arg_count++;
    }
    else
    {
        args = &argv[1];
        arg_count = argc - 1;
    }

    for (i = 0; i < arg_count; i++)
    {
        if (!is_valid_number(args[i]))
        {
            ret = 0;
            break;
        }
        num = ft_atoi(args[i]);
        if (num < -2147483648 || num > 2147483647)
        {
            ret = 0;
            break;
        }
        if (is_duplicate(*stack_a, (int)num))
        {
            ret = 0;
            break;
        }
        stack_push(stack_a, (int)num, arg_count - i - 1);
    }

    if (argc == 2 && args && args != &argv[1])
    {
        int j = 0;
        while (args[j])
            free(args[j++]);
        free(args);
    }
    return ret;
}
