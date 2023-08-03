#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: pointer to the node to find the sibling of
 *
 * Return: pointer to the sibling node, or NULL if node has no sibling
 *
 * Description: This function finds the
 * sibling of a given node in a binary tree.
 * The sibling of a node is another node in the tree that has the same parent.
 * If the node is NULL or it has
 * no parent (i.e., it's the root), the function returns NULL.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
