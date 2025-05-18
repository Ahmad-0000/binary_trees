#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL || tree->parent == NULL)
        return 0;

    while (tree)
    {
        tree = tree->parent;
        depth += 1;
    }
    return depth;
}
