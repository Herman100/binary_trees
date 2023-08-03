#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node after rotation,or NULL if not possible
 *
 * Description: This function performs a left rotation on a binary tree.
 * It rotates the given tree to the left around its root node,
 * preserving the in-order sequence of the nodes.
 * The left rotation is done by making the right child of the current
 * root the new root, moving the old root to be the left child of the new root
 * and adjusting the parent pointers accordingly.
 * If the given tree is NULL or it has
 * no right child (the rotation is not possible), the function returns NULL.
 */


binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->right)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left)
		new_root->left->parent = tree;
	new_root->left = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
