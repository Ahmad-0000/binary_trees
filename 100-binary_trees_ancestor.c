#include "binary_trees.h"

int is_child(const binary_tree_t *, const binary_tree_t *);

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *parent;

    if (first == NULL || second == NULL)
        return NULL;
    if (is_child(first, second))
        return (binary_tree_t *)first;
    if (is_child(second, first))
        return (binary_tree_t *)second;
    parent = first->parent;
    while(parent)
    {
        if (is_child(parent, second))
            return (binary_tree_t *)parent;
        parent = parent->parent;
    }
    return NULL;
}

int is_child(const binary_tree_t *parent, const binary_tree_t *node)
{
      int child = 0;

      if (parent == NULL)
          return 0;
      if (parent == node)
          return 1;
      child = is_child(parent->left, node);
      if (child == 1)
          return 1;
      child = is_child(parent->right, node);
      if (child == 1)
          return 1;
      return 0;
}
