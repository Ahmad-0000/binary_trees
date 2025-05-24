#include "binary_trees.h"

bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;
    bst_t *new_node;
    size_t i;

    if (array == NULL || size == 0)
      return NULL;
    for (i = 0; i < size; i++)
    {
        new_node = bst_insert(&root, array[i]);
        if (new_node == NULL)
            return root;
    }
    return root;
}
