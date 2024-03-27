#include "binary_trees.h"
int binary_t_height(const binary_tree_t *tree);

    /**
     * int binary_tree_balance - measures the balance factor of a binary tree
     *
     * @tree: is a pointer to the root node of the tree to measure the balance
     * factor
     *
     * Return: measured balance factor of a binary tree
     */

    int binary_tree_balance(const binary_tree_t *tree)
{
	int factor;

	if (tree == NULL)
		return (0);

	factor = binary_t_height(tree->left) -
		 binary_t_height(tree->right);
	return (factor);
}

/**
 * binary_t_height - measures the height of a node
 *
 * @tree:  is a pointer to the node height to be measured.
 *
 * Return: the measured height
 */

int binary_t_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);
	left_height = binary_t_height(tree->left);
	right_height = binary_t_height(tree->right);

	if (right_height > left_height)
		return (right_height + 1);
	return (left_height + 1);
}