#include "binary_trees.h"

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 *
 * Description: This function inserts a value into an
 * AVL tree while maintaining the AVL balance property.
 * If the tree is empty, it creates a new node and sets it as the root.
 * It traverses the tree until a suitable place for the new value is found,
 * ensuring the AVL balance property is maintained.
 * Returns a pointer to the newly inserted node, or NULL on failure.
 */


avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;
	avl_t *new_node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	if (value < (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->left), value);
		if (!new_node)
			return (NULL);
		(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->right), value);
		if (!new_node)
			return (NULL);
		(*tree)->right->parent = *tree;
	}
	else
		return (NULL);

	balance = binary_tree_balance(*tree);

	if (balance > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (new_node);
}
