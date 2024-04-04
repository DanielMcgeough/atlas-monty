int main()
{
	char opcode{5};
	int value;

	while (scanf("%4s", opcode) == 1)
	{
		if (strcmp(opdcode, "push") == 0)
		{
			if (scanf("%d", &value) != 1)
			{
				fprintf(stderr, "Error: usage: push int\n");
				exit(EXIT_FAILURE);
			}
			push(value);
	}
	else
	{
		void (*func)(stack_t **, unsigned int) = get_function(opcode);
		func(&stack_top, 0);
	}
	}  
	return 0;
}