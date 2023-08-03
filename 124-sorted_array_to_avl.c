#include "binary_trees.h"


avl_t *sorted_array_to_avl(int *array, size_t size);

/**
 * create_avl - creates an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @start: start index of the subarray
 * @end: end index of the subarray
 * @parent: pointer to the parent node
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = create_avl(array, start, mid - 1, root);
	root->right = create_avl(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (create_avl(array, 0, size - 1, NULL));
}
