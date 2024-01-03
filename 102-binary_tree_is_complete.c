#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	if (left_h >= right_h)
		return (1 + left_h);
	return (1 + right_h);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *lp, *rp;

	if (tree == NULL)
		return (1);
	lp = tree->left;
	rp = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (lp == NULL || rp == NULL)
		return (0);
	if (binary_tree_height(lp) == binary_tree_height(rp))
	{
		if (binary_tree_is_perfect(lp) && binary_tree_is_perfect(rp))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_he, r_he;
	binary_tree_t *lx, *rx;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	lx = tree->left;
	rx = tree->right;
	l_he = binary_tree_height(lx);
	r_he = binary_tree_height(rx);
	if (l_he == r_he)
	{
		if (binary_tree_is_perfect(lx) && binary_tree_is_complete(rx))
			return (1);
	}
	else if (l_he == r_he + 1)
	{
		if (binary_tree_is_complete(lx) && binary_tree_is_perfect(rx))
			return (1);
	}
	return (0);
}
