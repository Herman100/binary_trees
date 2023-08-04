#include "binary_trees.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * get_size - gets the size of a binary tree
 * @root: root of the binary tree
 *
 * Return: size of the binary tree
 */
int get_size(heap_t *root)
{
    if (root == NULL)
        return (0);

    return (1 + get_size(root->left) + get_size(root->right));
}

/**
 * is_complete - checks if a binary tree is complete
 * @root: root of the binary tree
 * @index: index of current node
 * @size: size of the binary tree
 *
 * Return: 1 if binary tree is complete, 0 otherwise
 */
int is_complete(heap_t *root, int index, int size)
{
    if (root == NULL)
        return (1);

    if (index >= size)
        return (0);

    return (is_complete(root->left, 2 * index + 1, size) &&
            is_complete(root->right, 2 * index + 2, size));
}

/**
 * heapify - turns a binary tree into a Max Binary Heap
 * @node: root of the binary tree
 */
void heapify(heap_t *node)
{
    heap_t *largest;

    if (node == NULL || node->left == NULL)
        return;

    largest = node;
    if (node->right != NULL && node->right->n > largest->n)
        largest = node->right;

    if (node->left->n > largest->n)
        largest = node->left;

    if (largest != node)
    {
        swap(&largest->n, &node->n);
        heapify(largest);
    }
}

/**
 * insert_node - inserts a new node in a complete binary tree
 * @root: root of the complete binary tree
 * @value: value to store in the new node
 *
 * Return: pointer to the new node
 */
heap_t *insert_node(heap_t **root, int value)
{
    heap_t *new_node;
    int size;

    size = get_size(*root);
    if (!is_complete(*root, 0, size))
        return (NULL);

    if (*root == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        return (*root = new_node);
    }

    if ((*root)->left == NULL)
    {
        new_node = binary_tree_node(*root, value);
        return ((*root)->left = new_node);
    }

    if ((*root)->right == NULL)
    {
        new_node = binary_tree_node(*root, value);
        return ((*root)->right = new_node);
    }

    if (!is_complete((*root)->left, 0, get_size((*root)->left)))
        return (insert_node(&(*root)->left, value));

    return (insert_node(&(*root)->right, value));
}


/**
 * heap_insert - inserts a value in Max Binary Heap
 *
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;

    new_node = insert_node(root, value);
    while (new_node->parent != NULL && new_node->n > new_node->parent->n)
    {
        swap(&new_node->n, &new_node->parent->n);
        new_node = new_node->parent;
    }

    return (new_node);
}
