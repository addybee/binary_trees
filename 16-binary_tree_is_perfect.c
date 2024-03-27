#include "binary_trees.h"

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
	int size_tree = (int)binary_tree_size(tree);
	/* check and return if the size is a power of 2 */
	if ((size_tree & (size_tree + 1)) == 0)
		return (1);
	return (0);
}

/**
* binary_tree_size - a function that measures the size of a binary tree
*
* @tree: a pointer to the root node of the tree to measure the size
*
* Return: return 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree->left) + 1
	+ binary_tree_size(tree->right);

	return (size);
}
