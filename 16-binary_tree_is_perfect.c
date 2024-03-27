#include "binary_trees.h"
int num_nodes(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - check if a binary tree is perfect from(node=2^h-1)
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 0 If tree is NULL or not perfect, 1 if perfect
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	/* get the number of nodes in the tree */
	int size_tree = num_nodes(tree);
	/* check and return if the size is a power of two */
	if ((size_tree & (size_tree + 1)) == 0)
		return (1);
	return (0);
}

/**
* num_nodes- a function that measures the size of a binary tree
*
* @tree: a pointer to the root node of the tree to measure the size
*
* Return: return 0 if tree is NULL
*/
int num_nodes(const binary_tree_t *tree)
{
	int size = 0;

	if (tree == NULL)
		return (0);

	size = num_nodes(tree->left) + 1
	+ num_nodes(tree->right);

	return (size);
}
