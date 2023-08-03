#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST.
 * @value: The value to insert into the BST.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 *
 * Description: This function inserts a value into a Binary Search Tree (BST)
 * If the tree is empty, it creates a new node and sets it as the root.
 * It traverses the tree until a suitable place for the new value is found,
 * ensuring the BST property is maintained.i
 * Returns a pointer to the newly inserted node.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp;

	if (!tree)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}

	temp = *tree;
	while (temp)
	{
		if (value < temp->n)
		{
			if (!temp->left)
			{
				temp->left = new_node;
				new_node->parent = temp;
				return (new_node);
			}
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			if (!temp->right)
			{
				temp->right = new_node;
				new_node->parent = temp;
				return (new_node);
			}
			temp = temp->right;
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}

	return (NULL);
}
