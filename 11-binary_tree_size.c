#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t bin_size = 0;

	if (tree)
	{
		bin_size += 1;
		bin_size += binary_tree_size(tree->left);
		bin_size += binary_tree_size(tree->right);
	}
	return (bin_size);
}
