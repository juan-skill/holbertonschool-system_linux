#include "holberton.h"

/**
 * get_op_func - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @option: string output format
 *
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_op_func(char *option))(char *dirpath)
{
	cml_t ops[] = {
		{"one", _ls_only},
		{"-1", _ls_minus_one},
	};

	register int i;

	for (i = 0; i < 2; i++)
		if (_strcmp(ops[i].option_flag, option) == 0)
			return (ops[i].fun_ptr);

	return (NULL);
}
