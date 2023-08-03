#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the binary tree, or 0 if tree is NULL
 *
 * Description: This function calculates the height of a binary tree,
 * which is the maximum depth (number of levels) of the tree.
 * If the tree is empty (NULL), the function returns 0.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height
			+ 1 : right_height + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: balance factor of the binary tree, or 0 if tree is NULL
 *
 * Description: This function calculates the
 * balance factor of a binary tree node,
 * which is the difference between the height of its
 * left subtree and the height of its right subtree.
 * A balance factor of 0 means the node is balanced, a negative
 * value means the left subtree is taller, and a positive value means the right
 * subtree is taller. If the tree is empty (NULL), the function returns 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
