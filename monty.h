#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *name);
int sep_line(char *buffer, int line_number, int format);
void reading(FILE *);
int len_chars(FILE *);
void function_ser(char *, char *, int, int);

/*Stack operations*/
stack_t *new_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void get_fun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nothing(stack_t **, unsigned int);
void change_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void node_inc(stack_t **, unsigned int);
void nodes_sub(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void node_multiple(stack_t **, unsigned int);
void node_mod(stack_t **, unsigned int);

/*String operations*/
void value_pr(stack_t **, unsigned int);
void string_pr(stack_t **, unsigned int);
void rotate_n(stack_t **, unsigned int);

/*Error hanlding*/
void error(int code_errors, ...);
void ex_error(int code_errors, ...);
void value_err(int code_errors, ...);
void rotate_l(stack_t **, unsigned int);

#endif
