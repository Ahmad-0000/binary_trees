#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t intrenal_nodes = 0;

    if (tree = NULL)
        return 0;
    if (tree->left || tree->right)
        internal_nodes++;
    internal_nodes += binary_tree_nodes(tree->left);
    internal_nodes += binary_tree_nodes(tree->right);
    return internal_nodes;
}
