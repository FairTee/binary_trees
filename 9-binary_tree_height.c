#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the binary tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_h = 0, right_h = 0;

		left_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
