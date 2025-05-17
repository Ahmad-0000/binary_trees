#include <stdlib.h>
#include "binary_trees.h"

/*
 * binary_tree_t - create a binary tree node
 *
 * @parent: parent of the new node
 * @value: integer value of the node
 * Return: return the node address when success or NULL when failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(*binary_tree_t));

    if (!node)
        return NULL;
    node->value = value;
    node->parent = parent;
    node->left = node->right = NULL;
    return node;
}
