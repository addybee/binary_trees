#include "binary_trees.h"

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
	binary_tree_t **queue =
		(binary_tree_t **)malloc(sizeof(binary_tree_t *) * 100);

	if (!queue)
		return (NULL);
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
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 *
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int rear, front;
	binary_tree_t **queue;
	binary_tree_t *temp_node;

	if (!tree || !func)
		return;
	queue = createQueue(&front, &rear);
	if (!queue)
		return;
	temp_node = (binary_tree_t *)tree;

	while (temp_node)
	{
		func(temp_node->n);

		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		temp_node = deQueue(queue, &front);
	}
	free(queue);
}
