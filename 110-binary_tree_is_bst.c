#include "binary_trees.h"

/**
 * bst_check - checks if a binary tree
 * is a valid Binary Search Tree (BST)
 * @tree: pointer to the root node of the tree to check
 * @min: the minimum value that a node in the tree can take
 * @max: the maximum value that a node in the tree can take
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 *
 * Description: This function recursively checks if the given binary tree is
 * a valid Binary Search Tree (BST). For each node, it ensures that the value
 * of the node is within the range defined by the minimum and maximum values.
 * If the tree is empty (NULL), it is considered a valid BST, and the function
 * returns 1.
 * If any node's value is outside the allowed range or if any subtree
 * is not a valid BST, the function returns 0,
 * indicating that the tree is not a valid BST.
 */
int bst_check(const binary_tree_t *tree, int min, int max)
{
    if (!tree)
        return (1);

    if (tree->n < min || tree->n > max)
        return (0);

    return (bst_check(tree->left, min, tree->n - 1) &&
            bst_check(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary
 * tree is a valid Binary Search Tree (BST)
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 *
 * Description: This function checks if the
 * given binary tree is a valid Binary Search Tree (BST).
 * A valid BST is a binary tree where for each node,
 * its left subtree contains only nodes with values less than the node's value
 * and its right subtree contains only nodes with values
 * greater than the node's value.
 * If the tree is empty (NULL), it is considered a valid BST,
 * and the function returns 1.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_check(tree, -2147483648, 2147483647));
}
