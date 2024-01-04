#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: input array
 * @size: size of array
 * Return: pointer to the root node
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t x = 0;
	heap_t *tree = NULL;

	if (!array)
		return (NULL);
	while (x < size)
	{
		heap_insert(&tree, array[x]);
		x++;
	}
	return (tree);
}
