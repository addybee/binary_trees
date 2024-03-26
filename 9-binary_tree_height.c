#include "binary_trees.h"

size_t height_bt(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree:  is a pointer to the root node of the tree to measure the height.
 *
 * Return: the measured height
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t height;
        
        if (tree == NULL)
                return (0);
        height = height_bt(tree);
        return (height);
}

/**
 * height_bt - gets the height of a binary tree
 *
 * @tree:  is a pointer to the root node of the tree to measure the height.
 * Return: the measured height
*/

size_t height_bt(const binary_tree_t *tree)
{
        size_t left_height, right_height;
        
        if (tree == NULL)
                return (-1);
        left_height = height_bt(tree->left);
        right_height = height_bt(tree->right);

        if (right_height > left_height)
                return (right_height + 1);
        return (left_height + 1);
}