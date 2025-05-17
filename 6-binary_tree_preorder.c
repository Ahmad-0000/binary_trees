#include "stdio.h"
#include "binary_trees.h"


void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;
    if (tree == NULL)
        return;
    func(tree->n);
    binary_tree_preorder(tree->left);
    binary_tree_preorder(tree->right);
}
