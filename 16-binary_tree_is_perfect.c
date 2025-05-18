#include "binary_trees.h"


size_t binary_t_size(const binary_tree_t *tree);
int binary_t_height(const binary_tree_t *tree);
void get_binary_t_height(const binary_tree_t *, int, int *);

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int i;
    int height;
    size_t size;
    size_t expected_size = 1;

    if (tree == NULL)
        return 0;
    size = binary_t_size(tree);
    height = binary_t_height(tree);
    if (height == -1)
        return 0;
    for (i = 0; i < height + 1; i++)
        expected_size *= 2;
    expected_size--;
    if (size == expected_size)
        return 1;
    return 0;
}


size_t binary_t_size(const binary_tree_t *tree)
{
    size_t size = 0;

    if (tree == NULL)
      return 0;

    size++;
    size += binary_t_size(tree->left);
    size += binary_t_size(tree->right);
    return size;
}


int binary_t_height(const binary_tree_t *tree)
{
    int current_height = 0;
    int real_height = 0;

    if (tree == NULL)
        return -1;
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
