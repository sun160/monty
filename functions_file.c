#include "monty.h"

/**
 * open_file - opens a file
 * @name: the file name
 * Return: void
 */

void open_file(char *name)
{
	FILE *fd = fopen(name, "r");

	if (name == NULL || fd == NULL)
		error(2, name);

	reading(fd);
	fclose(fd);
}


/**
 * reading - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void reading(FILE *fd)
{
	int num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (num = 1; getline(&buffer, &len, fd) != -1; num++)
	{
		format = sep_line(buffer, num, format);
	}
	free(buffer);
}


/**
 * sep_line - Separates each line.
 * @buffer: line from the file
 * @line_number: line number
 * @format: storage format.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int sep_line(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *m = "\n ";

	if (buffer == NULL)
		error(4);

	opcode = strtok(buffer, m);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, m);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	function_ser(opcode, val, line_number, format);
	return (format);
}

/**
 * function_ser - search for function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void function_ser(char *opcode, char *value, int ln, int format)
{
	int i;
	int mark;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nothing},
		{"swap", change_nodes},
		{"add", node_inc},
		{"sub", nodes_sub},
		{"div", div_nodes},
		{"mul", node_multiple},
		{"mod", node_mod},
		{"pchar", value_pr},
		{"pstr", string_pr},
		{"rotl", rotate_n},
		{"rotr", rotate_l},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (mark = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			get_fun(func_list[i].f, opcode, value, ln, format);
			mark = 0;
		}
	}
	if (mark == 1)
		error(3, ln, opcode);
}


/**
 * get_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string represent a value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier.
 */
void get_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int mark;
	int i;

	mark = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			mark = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = new_node(atoi(val) * mark);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
