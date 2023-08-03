#include "binary_trees.h"

/**
 * array_to_bst - Creates a Binary Search Tree (BST) from an array of integers
 * @array: Pointer to the array of integers.
i * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 *
 * Description: This function creates a
 * Binary Search Tree (BST) from an array of integers.
 * If the array is NULL or empty (size is 0), the function returns NULL.
 * It iterates through the array and inserts
 * each element into the BST using the bst_insert function,
 * effectively creating a valid BST.
 * Returns a pointer to the root node of the created BST.
 */


bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (!array || size == 0)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
