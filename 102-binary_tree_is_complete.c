#include "binary_trees.h"
#define TRUE 1
#define FALSE 0

int power(int, unsigned);

int binary_tree_is_complete(const binary_tree_t *tree)
{
      const binary_tree_t *roots[100], *children[200];
      int roots_front, roots_rear, children_front, children_rear, null_to_left;
      unsigned level = 1;

      if (tree == NULL)
          return FALSE;
      roots_front = children_front = 0;
      roots_rear = children_rear = -1;
      roots[++roots_rear] = tree;
      while (roots_front <= roots_rear)
      {
          if (roots[roots_front] && roots[roots_front]->right && roots[roots_front]->left == NULL)
              return FALSE;
          if (roots[roots_front])
          {
              children[++children_rear] = roots[roots_front]->left;
              children[++children_rear] = roots[roots_front]->right;
          }
          roots_front++;
          if (roots_front > roots_rear)
          {
              if (roots_front != power(2, level++) && children_rear != -1)
                  for (roots_front = 0, null_to_left = FALSE; roots_front <= roots_rear; roots_front++)
                  {
                      if (roots[roots_front] == NULL)
                          null_to_left = TRUE;
                      else if (roots[roots_front] && null_to_left)
                          return FALSE;
                  }
              else
                  return FALSE;
              while (children_front <= children_rear && children_front < 100)
              {
                  roots[children_front] = children[children_front];
                  children_front++;
              }
              roots_rear = children_front - 1;
              children_rear = -1;
              children_front = roots_front = 0;
          }
      }
      return TRUE;
}

int power(int base, unsigned pow)
{
    unsigned i;
    int result = 1;

    if (pow == 0)
        return 1;
    i = 0;
    while (i < pow)
    {
        result *= base;
        i++;
    }
    return result;
}
