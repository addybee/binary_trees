#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs left rotation on a binary tree
 *
 * @tree: is a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = NULL;

	if (!tree || !tree->left)
		return (tree);

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right)
		new_root->right->parent = tree;

	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;
	return (new_root);
}
