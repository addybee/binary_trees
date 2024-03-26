#include "binary_trees.h"
/**
 * binary_tree_nodes - a function that counts the nodes with at
 * least 1 child in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: return 0 is tree is NULL
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		count_nodes = binary_tree_nodes(tree->right) +
		binary_tree_nodes(tree->left) + 1;
	return (count_nodes);

}
