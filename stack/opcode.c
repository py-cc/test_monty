#include "monty.h"

void function_instruction(char *token, int number, unsigned int line_number, stack_t **head)
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
		if (strcmp(ops[i].opcode, token) == 0)
		{
			ops[i].f(head, number, line_number);
		}
		i++;
	}

}

void fun_pall(stack_t **head, int number __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = NULL;

	if (head == NULL)
		return;

	while((*head)->next != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		printf("%d\n", tmp->n);
		free(tmp);
	}
	printf("%d\n", (*head)->n);

}

void fun_push(stack_t **head, int number, unsigned int line_number __attribute__((unused)))
{
		stack_t *new_node;

		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
				return;

		new_node->n = number;
		new_node->prev = NULL;
		new_node->next = NULL;

		if (head == NULL)
		{
			*head = new_node;
		}
		else
		{
			new_node->next = *head;
			*head = new_node;
		}
}
