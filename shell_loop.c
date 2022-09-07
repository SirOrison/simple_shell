#include "main.h"

/**
 * without_comment - deletes comments from the input
 * @in: input string
 * Return: input without comments
 */

char *without_comment(char *in)
{
	int j;
	int roda;

	roda = 0;
	for (j = 0; in[j]; j++)
	{
		if (in[j] == '#')
		{
			if (j == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[j - 1] == ' ' || in[j - 1] == '\t' || in[j - 1] == ',')
				roda = j;

		}
	}
	if (roda != 0)
	{
		in = _realloc(in, j, roda + 1);
		in[roda] = '\0';
	}
	return (in);
}


/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 * Return: no return
 */

void shell_loop(data_shell *datash)
{
	int red, day;
	char *input;

	red = 1;
	while (red == 1)
	{
		write(STDIN_FILENO, "^-^", 4);
		input = read_line(&day);
		if (day != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;
			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			red = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			red = 0;
			free(input);
		}
	}
}
