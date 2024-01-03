#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: Num of nodes with at least 1 child in the bin tree, 0 if tree NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t bin_nodes = 0;

	if (tree)
	{
		bin_nodes += (tree->left || tree->right) ? 1 : 0;
		bin_nodes += binary_tree_nodes(tree->left);
		bin_nodes += binary_tree_nodes(tree->right);
	}
	return (bin_nodes);
}
