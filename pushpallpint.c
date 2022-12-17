#include "monty.h"

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t)); /* not freed */
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		fclose(globes.fm);
		exit(EXIT_FAILURE);
	}
	tmp->n = globes.data;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (*stack != NULL)
	{
		tmp->next = *stack;
		(*stack)->prev = tmp;
	}
	*stack = tmp;
}
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 *
 *
 *
 **/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if(tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
