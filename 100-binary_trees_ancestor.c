#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL if not found
 *
 * Description: This function finds the lowest
 * common ancestor (LCA) of two nodes
 * in a binary tree. The lowest common ancestor
 * is the deepest node that is a common
 * ancestor of both given nodes. If either of the nodes is NULL,
 * the function returns NULL.
 * If no common ancestor is found (e.g., when
 * the two nodes belong to different trees),
 * the function returns NULL as well.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		temp = second;
		while (temp)
		{
			if (temp == first)
				return ((binary_tree_t *)first);
			temp = temp->parent;
		}
		first = first->parent;
	}

	return (NULL);
}
