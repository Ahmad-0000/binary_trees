#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return NULL;
    while (tree)
    {
        if (value == tree->n)
            return (bst_t *)tree;
        else if (value < tree->n)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return NULL;
}
