#include "monty.h"

stack_t *stack_top = NULL;

void push(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        {
            fprintf(stderr, "Error: Allocation failed\n:"):
            exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = stack_top;
        new_node->next = NULL;
        if (stack_top != NULL) {
            stack_top->next = new_node;
        }
        stack_top = new_node;
}

int pop() 
{
    if (stack_top == NULL)
    {
        fprintf(stderr, "Error: Stack empty\n");
        exit(EXIT_FAILURE);
    }
    int value = stack_top->n;
    stack_t *temp = stack_top;
    stack_top = stack_top->prev;
    if (stack_top != NULL)
    {
        stack_top->next = NULL;
    }
    free(temp);
    return value;
}

void swap()
{
    if (stack_top == NULL || stack_top->prev == NULL)
    {
        fprintf(stderr, "Error: not enough elements\n");
        exit(EXIT_FAILURE);
    }
    int temp = stack_top->n;
    stack_top->n = stack_top->prev->n;
    stack_top->prev->n = temp;
}

void add()
{
    if (stack_top == NULL || stack_top->prev == NULL)
    {
        fprintf(stderr, "Error: not enough elements for add\n");
        exit(EXIT_FAILURE);
    }
    stack_tip->prev->n += stack_top->n;
    pop();
}

void pall()
{
    stack_t *current = stack_top;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->prev;
    }
}