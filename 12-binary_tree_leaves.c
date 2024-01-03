#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of leaves
 *
 * Return: Number of leaves in the binary tree, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t bin_leaves = 0;

	if (tree)
	{
		bin_leaves += (!tree->left && !tree->right) ? 1 : 0;
		bin_leaves += binary_tree_leaves(tree->left);
		bin_leaves += binary_tree_leaves(tree->right);
	}
	return (bin_leaves);
}
