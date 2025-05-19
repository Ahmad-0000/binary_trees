#include "binary_trees.h"
#include <stdio.h>

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    const binary_tree_t *roots_queue[100];
    const binary_tree_t *children_queue[200];
    int roots_rear, children_rear, roots_front, children_front;

    roots_rear = children_rear = -1;
    roots_front = children_front = 0;
    if (tree == NULL || func == NULL)
        return;
    roots_rear++;
    roots_queue[roots_rear] = tree;
    while (roots_front <= roots_rear)
    {
        func(roots_queue[roots_front]->n);
        if (roots_queue[roots_front]->left)
        {
            children_rear++;
            children_queue[children_rear] = roots_queue[roots_front]->left;
        }
        if (roots_queue[roots_front]->right)
        {
            children_rear++;
            children_queue[children_rear] = roots_queue[roots_front]->right;
        }
        roots_front++;
        if (roots_front > roots_rear && children_rear != -1)
        {
            roots_rear = -1;
            roots_front = 0;
            while (children_front <= children_rear && children_front < 100)
            {
                roots_queue[children_front] = children_queue[children_front];
                children_front++;
            }
            roots_rear = children_front - 1;
            roots_front = 0;
            children_front = 0;
            children_rear = -1;
        }
    }
}
