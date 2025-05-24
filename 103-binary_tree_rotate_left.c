#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *temp;

    if (tree == NULL || tree->parent)
        return NULL;
    if (tree->right == NULL)
    {
        tree->right = tree->left;
        tree->left = NULL;
        return tree;
    }
    else
    {
        temp = tree->right;
        temp->parent = NULL;
        tree->parent = tree->right;
        if (temp->left)
          tree->right = temp->left;
        else
          tree->right = NULL;
        temp->left = tree;
    }
    return temp;
}
