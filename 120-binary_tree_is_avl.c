#include "binary_trees.h"
#include <limits.h>

int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
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
 * is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value
 * @max: maximum value
 * @height: height of the tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max, size_t *height)
{
	size_t left_height, right_height;

	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_height = 0;
	right_height = 0;
	if (!is_avl(tree->left, min, tree->n - 1, &left_height) ||
			!is_avl(tree->right, tree->n + 1, max, &right_height))
		return (0);

	*height = MAX(left_height, right_height) + 1;
	return (ABS((int)(left_height - right_height)) <= 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = 0;
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}
