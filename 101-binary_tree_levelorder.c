#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_perform_on_level - perform a function on a
 * specific level of a binary tree
 * @tree: pointer to the root of the tree
 * @lev: level of the tree to perform a function on
 * @func: function to perform
 *
 * Return: void
 */
void binary_tree_perform_on_level(const binary_tree_t *tree,
		size_t lev, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (lev == 1)
		func(tree->n);
	else if (lev > 1)
	{
		binary_tree_perform_on_level(tree->left, lev - 1, func);
		binary_tree_perform_on_level(tree->right, lev - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary
 * tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, x;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (x = 1; x <= height; x++)
		binary_tree_perform_on_level(tree, x, func);
}
