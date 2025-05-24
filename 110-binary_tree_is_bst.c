#include "binary_trees.h"

int is_bst(const binary_tree_t *);
int check_left_values(const binary_tree_t *, int);
int check_right_values(const binary_tree_t *, int);

int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    return is_bst(tree);
}

int is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;
    if (!check_left_values(tree->left, tree->n))
        return 0;
    if (!check_right_values(tree->right, tree->n))
        return 0;
    if (!is_bst(tree->left))
        return 0;
    if (!is_bst(tree->right))
        return 0;
    return 1;
}

int check_left_values(const binary_tree_t *tree, int root_value)
{
    if (tree == NULL)
        return 1;
    if (tree->n >= root_value)
        return 0;
    if (!check_left_values(tree->left, root_value))
        return 0;
    if (!check_left_values(tree->right, root_value))
        return 0;
    return 1;
}

int check_right_values(const binary_tree_t *tree, int root_value)
{
    if (tree == NULL)
        return 1;
    if (tree->n <= root_value)
        return 0;
    if (!check_right_values(tree->right, root_value))
        return 0;
    if (!check_right_values(tree->left, root_value))
        return 0;
    return 1;
}
