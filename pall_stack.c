#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pall - printsa all values on the stack
 * @stack: pointer to the pointer of the top of a stack
 * @line_number: it indciates the line number in the monty code file
 * Return: the function does not return a value
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
