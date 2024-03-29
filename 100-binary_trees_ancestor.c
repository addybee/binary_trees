#include "binary_trees.h"
binary_tree_t *findLCA(const binary_tree_t *root, int key1, int key2);
const binary_tree_t *root_node(const binary_tree_t *node);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: pointer to lowest common ancestor node of the two nodes or NULL
 * if there is no ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *root1 = root_node(first);
	const binary_tree_t *root2 = root_node(second);

	if (!first || !second || root1 != root2)
		return (NULL);

	return (findLCA(root1, first->n, second->n));
}

/**
 * root_node - find the root node of a given node
 *
 * @node: the node whose root is to be found
 *
 * Return: the root node
*/
const binary_tree_t *root_node(const binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (!node->parent)
		return (node);
	while (node->parent != NULL)
	{
		node = node->parent;
	}
	return (node);
}

/**
 * findLCA - returns pointer to LCA of two given values
 *
 * @root: the root node of the binary tree
 * @key1: the key of the first node
 * @key2: the key of the second node
 *
 * Return: the lowest common Ancestor node of the two keys
*/

binary_tree_t *findLCA(const binary_tree_t *root, int key1, int key2)
{
	binary_tree_t *left, *right;

	if (root == NULL)
		return (NULL);

	if (root->n == key1 || root->n == key2)
		return ((binary_tree_t *)root);

	left = findLCA(root->left, key1, key2);
	right = findLCA(root->right, key1, key2);

	if (left && right)
		return ((binary_tree_t *)root);

	return ((right) ? right : left);
}
