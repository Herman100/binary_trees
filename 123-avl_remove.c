#include "binary_trees.h"
#include <stdlib.h>

avl_t *avl_remove(avl_t *root, int value)
{
	int balance;
	avl_t *temp, *successor;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
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
			root->right = avl_remove(root->right, successor->n);
		}
	}

	balance = binary_tree_balance(root);

	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	else if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	else if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	else if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}

	return (root);
}
