#include "binary_trees.h"
int utility_is_perfect(const binary_tree_t *tree, int depth, int level);
int binary_t_depth(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - check if a binary tree is perfect from(node=2^h-1)
 *
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 0 If tree is NULL or not perfect, 1 if perfect
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int level = 0, depth_tree;

	if (tree == NULL)
		return (0);
	/* get the depth of nodes in the tree */
	depth_tree = binary_t_depth(tree);
	return (utility_is_perfect(tree, depth_tree, level));
}

/**
* binary_t_depth - measures the depth of a node in a binary tree
* @tree: pointer to the node to measure the depth
*
* Return: depth of the node
*/

int binary_t_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	while (tree)
	{
		depth += 1;
		tree = tree->left;
	}
	return (depth);
}


/**
 * utility_is_perfect - help binary_tree_is_perfect check if a binary tree
 * is perfect from(node=2^h-1)
 *
 * @tree: is a pointer to the root node of the tree to check
 * @depth: this the depth from any leaf to the root node that is measured
 * @level: this is the level of the current node during traversal of the tree
 * Return: 0 If tree is NULL or not perfect, 1 if perfect
*/

int utility_is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);
	if (!tree->left && !tree->right)
	{
		if (depth == level + 1)
			return (1);
		else
			return (0);
	}

	if (!tree->left || !tree->right)
		return (0);

	return (utility_is_perfect(tree->left, depth, level + 1) *
		utility_is_perfect(tree->right, depth, level + 1));
}
