#include "binary_trees.h"

binary_tree_t *binary_tree_sibling(binary_tree_t *tree)
{
    if (tree == NULL || tree->parent == NULL)
        return NULL;
    if (tree->parent->left == tree)
        return tree->parent->right;
    return tree->parent->left;
}
