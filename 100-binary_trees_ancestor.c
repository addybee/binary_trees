#include "binary_trees.h"

/**
* binary_trees_ancestor -  a function that finds the lowest common ancestor
* of two nodes in a binary tree
* @first:  is a pointer to the first node
* @second:  is a pointer to the second node
* Return:  the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	const binary_tree_t *temp = second;

	while (temp != NULL)
    {
		if (temp == first)
			return ((binary_tree_t *)first);
		temp = temp->parent;
	}


	temp = first;
	while (temp != NULL)
    {
		if (temp == second)
			return ((binary_tree_t *)second);
		temp = temp->parent;
	}

	temp = first->parent;
	const binary_tree_t *temp2 = second->parent;

	while (temp && temp2)
	{
		if (temp == temp2)
			return ((binary_tree_t *)temp);
		temp = temp->parent;
		temp2 = temp2->parent;
	}

	return (NULL);
}

