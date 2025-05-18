#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
    int full = 1;

    if (tree == NULL)
        return 0;
    if (tree->left && !tree->right || (tree->right && !tree->left))
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    full = binary_tree_is_full(tree->left);
    if (!full)
        return 0;
    full = binary_tree_is_full(tree->right);
    if (!full)
        return 0;
    return 1;
}
