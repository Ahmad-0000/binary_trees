#include <stdio.h>
#include "binary_trees.h"

const binary_tree_t *get_right_uncle(const binary_tree_t *);
const binary_tree_t *get_left_of_level(const binary_tree_t *);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    const binary_tree_t *right_uncle;
    const binary_tree_t *most_left;

    if (tree == NULL || func == NULL)
      return;
    func(tree->n);
    right_uncle = get_right_uncle(tree);
    most_left = get_left_of_level(tree);
    if (tree->parent && tree->parent->right && tree->parent->right != tree)
      binary_tree_levelorder(tree->parent->right, func);
    else if (right_uncle)
        binary_tree_levelorder(right_uncle->left ? right_uncle->left : right_uncle->right, func);
    else if ((most_left) && (most_left->left || most_left->right))
        binary_tree_levelorder(most_left->left ? most_left->left : most_left->right, func);
    else
    {
        if (most_left->parent && most_left->parent->right && most_left->parent->right != tree)
        {
            binary_tree_levelorder(most_left->parent->right->left ? most_left->parent->right->left : most_left->parent->right->right, func);
        }
    }

}

const binary_tree_t *get_right_uncle(const binary_tree_t *tree)
{
    if (tree == NULL || tree->parent == NULL || tree->parent->parent == NULL)
      return NULL;
    if (tree->parent->parent->right == tree->parent)
      return NULL;
    return tree->parent->parent->right;
}

const binary_tree_t *get_left_of_level(const binary_tree_t *node)
{
    if (node == NULL)
        return NULL;
    if (node->parent == NULL)
        return node;
    while (node->parent->left)
    {
        if (node->parent->left != node)
        {
            node = node->parent->left;
        }
        else if (node->parent->parent)
        {
            if (node->parent->parent->left && node->parent->parent->left != node->parent)
            {
                if (node->parent->parent->left->left)
                    node = node->parent->parent->left->left;
                else if (node->parent->parent->left->right)
                    node = node->parent->parent->left->right;
                else
                    break;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return node;
}
