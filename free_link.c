#include "shell.h"

/**
 * print_linked_list - Print a linked list of strings.
 *
 * @head: The head of the linked list.
 *
 * Return: The size of the linked list.
 */
size_t print_linked_list(list_t *head)
{
	list_t *current = head;
	size_t count = 0;

	if (head == NULL)
		return (0);

	while (current != NULL)
	{
		if (current->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			size_t len = _strlen(current->var);
			write(STDOUT_FILENO, current->var, len);
			write(STDOUT_FILENO, "\n", 1);
		}
		current = current->next;
		count++;
	}

	return (count);
}

/**
 * add_node_to_end - Add a node to the end of a linked list.
 *
 * @head: A pointer to the head of the linked list.
 * @str: The data to add to the new node.
 *
 * Return: A pointer to the new linked list.
 */
list_t *add_node_to_end(list_t **head, const char *str)
{
	list_t *new_node, *current;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->var = _strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}

	return (*head);
}

/**
 * delete_node_at_index - Delete a node at a given index in a linked list.
 *
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to delete.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *current, *temp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free((*head)->var);
		free(*head);
		*head = temp;
		return (1);
	}

	current = *head;
	for (i = 0; i < index - 1 && current != NULL; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp->var);
	free(temp);

	return (1);
}

/**
 * free_linked_list - Free a linked list of strings.
 *
 * @list: The linked list to free.
 */
void free_linked_list(list_t *list)
{
	list_t *current, *temp;

	current = list;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->var);
		free(temp);
	}
}
