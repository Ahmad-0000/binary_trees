#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *temp, *new_node;

    if (tree == NULL)
        return NULL;
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }
    temp = *tree;
    while (1)
    {
        if (value < temp->n)
        {
          if (temp->left == NULL)
            break;
          temp = temp->left;
        }
        if (value > temp->n)
        {
          if (temp->right == NULL)
            break;
          temp = temp->right;
        }
        if (value == temp->n)
          return NULL;
    }
    new_node = binary_tree_node(temp, value);
    if (new_node == NULL)
        return NULL;
    if (new_node->n < temp->n)
        temp->left = new_node;
    else
        temp->right = new_node;
    return new_node;
}
