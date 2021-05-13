#include "monty.h"

/* (: funciono*/

int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	size_t size_len = 0;
	char *token;
	int cont;
	int line_number = 0;
	char *tmp = NULL;
	const char s[2] = " \n";
	stack_t *head = NULL;
	int number;

	if (argc != 2)
		return (0); /* Provisional toca buscar el error */


	file = fopen(argv[1], "r");     /* algun manejo de errores */
	while (getline(&buffer, &size_len, file) != EOF)
	{
		/* get the first token */
		token = strtok(buffer, s);

		cont = 0;
		while (token != NULL)
		{
			cont++;
			/*token = push (1) = (1)(2nd)*/
			  if (cont == 2)
			  {
				number = atoi(token);
				token = tmp;
			  	function_instruction(token, number, line_number, &head);
			  }
			  else if (cont == 1 && (strcmp(token, "pall") == 0))
			  {
			  	function_instruction(token, number, line_number, &head);
			  }
			  tmp = token;
			token = strtok(NULL, s);

		}
		line_number++;
	}
	free(buffer);
	free(head);
	fclose(file);
	return (0);
}
