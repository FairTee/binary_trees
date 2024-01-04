#include "binary_trees.h"

/**
 * num_of_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int num_of_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + num_of_nodes(root->left) +
			num_of_nodes(root->right));
}

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x, nu, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nu = num_of_nodes(heap);
	arr = malloc(sizeof(*arr) * nu);
	if (!arr)
		return (NULL);

	*size = nu;
	for (x = 0; x < nu; x++)
		arr[x] = heap_extract(&heap);

	return (arr);
}
