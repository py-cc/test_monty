#include "monty.h"


int main(int argc, char **argv)
{
        FILE *file;
        char *buffer = NULL;
        size_t size_len = 0;
	char *token;
	int cont;
/*	char *tmp = NULL;*/
	const char s[2] = " ";

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
			printf("%s\n", token);
			/*token = push (1) = (1)(2nd)
			if (cont == 2)
			{
				 hacemos el llamdo a la funcion con temp y arg
			}
			tmp = token; */
			token = strtok(NULL, s);

		}
        }
        return (0);
}
