#include "monty.h"

void opcode(char *string)
{
	instruction_t ops[] = {

		{"push", fun_push},
		{"pall", fun_pall},
		{NULL, NULL}
	};
	int i;
	i = 0;

	while(ops[i].opcode)
	{
}
