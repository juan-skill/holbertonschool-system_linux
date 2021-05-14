#include <Python.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_python_bytes - prints information about python bytes object
 *
 * @p: pointer to python bytes object
 * Return: nothing
 */
void print_python_bytes(PyObject *p)
{
	ssize_t sz, i = 0;

	printf("[.] bytes object info\n");

	if (p->ob_type != &PyBytes_Type)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	sz = ((PyVarObject *)p)->ob_size;
	printf("  size: %ld\n", sz);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);

	if (sz < 9)
		sz += 1;
	else
		sz = 10;

	printf("  first %ld bytes: ", sz);
	for (i = 0; i < sz; i++)
	{
		printf("%02hhx%c",
			((PyBytesObject *)p)->ob_sval[i], i + 1 == sz ? '\n' : ' ');
	}

}

/**
 * print_python_list - prints info about a python list
 *
 * @p: pointer to python object struct
 * Return: nothing
 */
void print_python_list(PyObject *p)
{
	ssize_t sz = 0, i = 0;
	PyObject *pobj = NULL;

	sz = ((PyVarObject *)p)->ob_size;

	printf("%s", "[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", sz);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < sz; i++)
	{
		pobj = ((PyListObject *)p)->ob_item[i];

		printf("Element %ld: %s\n", i, pobj->ob_type->tp_name);

		if (pobj->ob_type == &PyBytes_Type)
			print_python_bytes(pobj);
	}
}
