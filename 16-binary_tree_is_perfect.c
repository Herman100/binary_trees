#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: height of the binary tree, or -1 if tree is NULL
 *
 * Description: This function calculates the height of a binary tree,
 * which is the maximum depth (number of levels) of the tree.
 * If the tree is empty (NULL), the function returns -1.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height > right_height ? left_height
			+ 1 : right_height + 1);
}



/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise or if tree is NULL
 *
 * Description: This function checks if a binary tree is full,
 * which means every node in the tree has either zero or two children.
 * If the tree is empty (NULL), the function returns 0.
 */


int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	return (0);
}



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL
 *
 * Description: This function checks if a binary tree is perfect,
 * which means all levels of the tree are fully filled.
 * If the tree is empty (NULL), the function returns 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height && binary_tree_is_full(tree))
		return (1);

	return (0);
}
