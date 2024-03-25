#include "binary_trees.h"

void delete_tree(binary_tree_t *parent);

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: is the pointer to the root node of the tree to delete
*/
void binary_tree_delete(binary_tree_t *tree)
{
        if (tree == NULL)
                return;
        binary_tree_delete(tree->left);
        if (tree != NULL)
        {
                free (tree);
                tree = NULL;
        }
        binary_tree_delete(tree->right);      
}

void delete_tree(binary_tree_t *parent)
{
        if (parent == NULL)
                return;
        free (parent);
        parent = NULL;
}