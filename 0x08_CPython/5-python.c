#include <Python.h>
#include <stdio.h>

/**
 * print_python_int - prints a python integer
 * @p: pointer to python object
 */
void print_python_int(PyObject *p)
{
	Py_ssize_t size = 0, i = 0;
	digit *digit = NULL;
	unsigned long value = 0;

	if (p == NULL || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}

	size = ((PyVarObject *)(p))->ob_size;
	digit = ((PyLongObject *)(p))->ob_digit;

	if (abs(size) > 3 || (abs(size) == 3 && digit[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		return;
	}

	for (i = 0; i < abs(size); i++)
	{
		value += digit[i] * (1L << (i * PyLong_SHIFT));
	}

	if (size < 0)
		printf("-");

	printf("%lu\n", value);
}
