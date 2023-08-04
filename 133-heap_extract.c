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
 * get_last_node - gets the last node in level-order traversal
 * @root: root of the binary tree
 *
 * Return: last node in level-order traversal
 */
heap_t *get_last_node(heap_t **root)
{
    heap_t **queue;
    heap_t **temp;
    heap_t **last_node;
    int i, size;

    size = get_size(*root);
    queue = malloc(sizeof(heap_t *) * size);
    if (queue == NULL)
        return (NULL);

    temp = queue;
    last_node = queue;
    *(temp++) = *root;
    while (*last_node != NULL)
    {
        if ((*last_node)->left != NULL)
            *(temp++) = (*last_node)->left;

        if ((*last_node)->right != NULL)
            *(temp++) = (*last_node)->right;

        last_node++;
    }

    last_node--;
    for (i = 0; i < size; i++)
        if (queue[i] == (*last_node)->parent && queue[i]->right == (*last_node))
            queue[i]->right = NULL;
        else if (queue[i] == (*last_node)->parent && queue[i]->left == (*last_node))
            queue[i]->left = NULL;

    free(queue);
    return (*last_node);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 *
 * @root: double pointer to the root node of heap
 *
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *last_node;

    if (root == NULL || *root == NULL)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(root);
    if (last_node != NULL && last_node != (*root))
        swap(&(*root)->n, &last_node->n);

    free(last_node);
    heapify(*root);
    return (value);
}

