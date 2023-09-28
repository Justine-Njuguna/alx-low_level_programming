#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	char *password = malloc(sizeof(char) * 5);
	char characters[5] = {'H', 'e', 'l', 'l', '\0'};
	char command[100];
	int i;

	for (i = 0; characters[i]; i++)
		password[i] = characters[i];

	password[i] = '\0';

	sprintf(command, "echo %s > 101-password", password);
	system(command);

	free(password);

	return (0);
}
