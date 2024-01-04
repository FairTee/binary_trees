#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of
 * integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr;
	int pull, x = 0;
	size_t size_h;

	if (!heap)
		return (NULL);
	size_h = binary_tree_size(heap);
	*size = size_h;
	arr = malloc(size_h * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		pull = heap_extract(&heap);
		arr[x] = pull;
		x++;
	}
	return (arr);
}
