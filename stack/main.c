#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	char *string = NULL;
	size_t size_len = 0;
	char *tmp;

	if (argc != 2)
		return (0); // Provisional toca buscar el error

	file = fopen(argv[1], "r");	// algun manejo de errores

	while (getline(&buffer, &size_len, file) != EOF)
	{
		string = strtok(buffer, " \n");
		if (string != NULL)
		{
			printf("%s\n", string);
			string = strtok(NULL, " \n");
		}


	}
	return (0);
}
