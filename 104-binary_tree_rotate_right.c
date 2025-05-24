#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *temp;

    if (tree == NULL)
      return NULL;
    if (tree->left == NULL)
    {
        tree->left = tree->right;
        tree->right = NULL;
        return tree;
    }
    else
    {
        temp = tree->left;
        temp->parent = NULL;
        tree->parent = temp;
        if (temp->right)
          tree->left = temp->right;
        else
          tree->left = NULL;
        temp->right = tree;
    }
    return temp;
}
