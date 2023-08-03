#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array of integers.
 * @array: Pointer to the array of integers.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node
 * of the created AVL tree, or NULL on failure.
 *
 * Description: This function creates an AVL tree from an array of integers.
 * If the array is NULL or empty (size is 0), the function returns NULL.
 * It iterates through the array and inserts
 * each element into the AVL tree using the avl_insert function,
 * effectively creating a balanced AVL tree.
 * Returns a pointer to the root node
 * of the created AVL tree, or NULL on failure.
 */


avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
