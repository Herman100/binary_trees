#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST.
 * @value: The value to search for.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 *
 * Description: This function searches for a value
 * in a Binary Search Tree (BST).
 * If the tree is empty (NULL) or the value is
 * not found, the function returns NULL.
 * It iteratively compares the value with the
 * nodes' values, traversing the tree left or right
 * based on the comparisons until the
 * value is found or the end of the tree is reached.
 * Returns a pointer to the node containing the value, or NULL if not found.
 */



bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

	if (value < tree->n)
		tree = tree->left;
	else
		tree = tree->right;
	}

	return (NULL);
}
