#include "binary_trees.h"
binary_tree_t **createQueue(int *front, int *rear);
void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *temp_node);
binary_tree_t *deQueue(binary_tree_t **queue, int *front);

/**
 * createQueue - creates a queue of size 100
 *
 * @front: index of the element to be remove from the queue
 * @rear: index of where the element will be added
 *
 * Return: pointer to array to binary_tree_t struct
*/

binary_tree_t **createQueue(int *front, int *rear)
{
	binary_tree_t **queue = NULL;
	int i;

	queue = (binary_tree_t **)malloc(sizeof(binary_tree_t *) * 300);
	if (queue == NULL)
		return (NULL);
	for (i = 0; i < 300; i++)
	{
		queue[i] = NULL;
	}
	*front = *rear = 0;
	return (queue);
}

/**
 * enQueue - add elements to a queue
 *
 * @queue: the queue in which an element is to be added
 * @rear: index of where the element will be added
 * @temp_node: pointer to the node to be added to the queue
 */

void enQueue(binary_tree_t **queue, int *rear, binary_tree_t *temp_node)
{
	queue[*rear] = temp_node;
	(*rear)++;
}

/**
 * deQueue - pop an elements from a queue
 *
 * @queue: the queue in which an element is to be popped
 * @front: index of the element to be remove from the queue
 *
 * Return: the popped element
 */

binary_tree_t *deQueue(binary_tree_t **queue, int *front)
{
	(*front)++;
	return (queue[*front - 1]);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 0 If tree is NULL or not full, 1 if complete
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int rear = 0, front = 0, is_not_full_node;
	binary_tree_t **queue;
	binary_tree_t *temp_node;

	if (!tree)
		return (0);
	queue = createQueue(&front, &rear);
	if (!queue)
		return (0);
	is_not_full_node = 0;
	enQueue(queue, &rear, (binary_tree_t *)tree);

	while (front != rear)
	{
		temp_node = deQueue(queue, &front);

		if (temp_node->left)
		{
			if (is_not_full_node)
			{
				free(queue);
				return (0);
			}
			enQueue(queue, &rear, temp_node->left);
		}
		else
			is_not_full_node = 1;

		if (temp_node->right)
		{
			if (is_not_full_node)
			{
				free(queue);
				return (0);
			}
			enQueue(queue, &rear, temp_node->right);
		}
		else
			is_not_full_node = 1;
	}
	free(queue);
	return (1);
}
