#include <stdlib.h>
#include "binary_trees.h"

/*
 * binary_tree_insert_left - a funcion to insert a node as a left child
 *      of another node in a binary tree
 *
 * @parent: the node to insert the new child into
 * @value: the data value of the new child
 * Return: the address of the new node, or NULL on failure
 */

binary_tree_t binary_tree_insert_left(binary_tree_t *parent, int value)
{
      binary_tree_t *node;

      if (parent == NULL)
          return NULL;
      node = binary_tree_node(parent, value);
      if (node == NULL)
          return NULL;
      if (parent->left)
          parent->left->parent = node;
      parent->left = node;
      return node;
}
