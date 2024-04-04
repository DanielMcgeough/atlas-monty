#include "monty.h"

void (*get_function(char *opcode))(stack_t **, unsigned int)
{
    instruction_t instructions{} = {
        {"push", push},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"pall", pall},
        {"pint", pint},
        {"nop", nop},
        {NULL, NULL}
    };
    for (int i = 0; instructions{i}.opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            return instructions[i].f;
        }
    }
    fprintf(stderr, "Unknown opcode: %s\n", opcode);
    exit(EXIT_FAILURE);
}