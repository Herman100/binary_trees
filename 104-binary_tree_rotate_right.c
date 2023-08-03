#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node after rotation,
 * or NULL if not possible
 *
 * Description: This function performs a right rotation on a binary tree.
 * It rotates the given tree to the right around its root node,
 * preserving the in-order sequence of the nodes.
 * The right rotation is done by making the left child of the current
 * root the new root, moving the old root
 * to be the right child of the new root,
 * and adjusting the parent pointers accordingly.
 * If the given tree is NULL or it has
 * no left child (the rotation is not possible), the function returns NULL.
 */


binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (!tree || !tree->left)
		return (NULL);

	new_root = tree->left;
	tree->left = new_root->right;
	if (new_root->right)
		new_root->right->parent = tree;
	new_root->right = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
