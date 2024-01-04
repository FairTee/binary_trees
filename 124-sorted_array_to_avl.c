#include "binary_trees.h"

/**
 * avl_recursive_array_sort - helper function for sorted_array_to_avl
 * @array: input array
 * @beg: starting index
 * @comp: ending index
 * @parent: pointer to parent node
 * Return: newly created node
 */
avl_t *avl_recursive_array_sort(int *array, int beg, int comp, avl_t *parent)
{
	avl_t *curr;
	int mdx;

	if (beg > comp)
		return (NULL);

	mdx = (beg + comp) / 2;
	curr = calloc(1, sizeof(avl_t));
	if (!curr)
		return (NULL);

	curr->n = array[mdx];
	curr->parent = parent;
	curr->left = avl_recursive_array_sort(array, beg, mdx - 1, curr);
	curr->right = avl_recursive_array_sort(array, mdx + 1, comp, curr);

	return (curr);
}


/**
 * sorted_array_to_avl - It builds an AVL tree from an array
 * @array: input array
 * @size: size of array
 * Return: NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (!array)
		return (NULL);
	return (avl_recursive_array_sort(array, 0, size - 1, NULL));
}
