#include "binary_trees.h"

void get_binary_t_height(const binary_tree_t *, int, int *);

size_t binary_tree_height(const binary_tree_t *tree)
{
    int current_height = 0;
    int real_height = 0;

    if (tree == NULL)
        return 0;
    get_binary_t_height(tree, current_height, &real_height);
    return real_height;
}

void get_binary_t_height(const binary_tree_t *tree, int current_h, int *max_h)
{
    if (tree == NULL)
        return;
    if (current_h > *max_h)
        *max_h = current_h;
    get_binary_t_height(tree->left, current_h + 1, max_h);
    get_binary_t_height(tree->right, current_h + 1, max_h);
}
