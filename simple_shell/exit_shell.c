#include "main.h"

/**
 * exit_shell - function that exits the shell
 * @datash: data relevant (status and args)
 * Return: 0 on success
 */

int exit_shell(data_shell *datash)
{
	unsigned int day;
	int is_digit, str_len, big_number;

	if (datash->args[1] != NULL)
	{
		day = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = day > (unsigned int) INT_MAX;

		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}

		datash->status = (day % 256);
	}
	return (0);
}
