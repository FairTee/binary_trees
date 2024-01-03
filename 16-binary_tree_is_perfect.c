#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	/* If the tree is not full, it can't be perfect */
	if (left_h != right_h)
		return (0);

	/* Recursively check if the left and right subtrees are perfect */
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}
