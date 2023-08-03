#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_remove - Removes a node with a given value from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node of the modified BST, or NULL if not found.
 *
 * Description: This function removes a node with the given value from a Binary Search Tree (BST).
 * If the value is found, the function removes the node and rearranges the tree as needed to maintain
 * the BST property. If the tree is empty (NULL) or the value is not found, the function returns NULL.
 * When removing a node with two children, it replaces the node with its in-order successor.
 * Returns a pointer to the root node of the modified BST, or NULL if not found.
 */


bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp, *successor;

    if (!root)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (!root->left && !root->right)
        {
            free(root);
            return (NULL);
        }
        else if (!root->left || !root->right)
        {
            temp = root->left ? root->left : root->right;
            free(root);
            return (temp);
        }
        else
        {
            successor = root->right;
            while (successor->left)
                successor = successor->left;
            root->n = successor->n;
            root->right = bst_remove(root->right, successor->n);
        }
    }

    return (root);
}
