#include "binary_trees.h"
#include "limits.h"

size_t tree_height(const binary_tree_t *tree);
int avl_aux(const binary_tree_t *tree, int lower_bound, int upper_bound);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_he = 0, right_he = 0;

		left_he = tree->left ? 1 + tree_height(tree->left) : 1;
		right_he = tree->right ? 1 + tree_height(tree->right) : 1;
		return ((left_he > right_he) ? left_he : right_he);
	}
	return (0);
}

/**
 * avl_aux - Checks to see if a binary tree is a valid AVL.
 * @tree: A pointer to the root node of the tree.
 * @lower_bound: The value of the smallest node
 * @upper_bound: The value of the largest node
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_aux(const binary_tree_t *tree, int lower_bound, int upper_bound)
{
	size_t left_he, right_he, diffx;

	if (tree != NULL)
	{
		if (tree->n < lower_bound || tree->n > upper_bound)
			return (0);

		left_he = tree_height(tree->left);
		right_he = tree_height(tree->right);
		diffx = left_he > right_he ? left_he - right_he : right_he - left_he;

		if (diffx > 1)
			return (0);

		return (avl_aux(tree->left, lower_bound, tree->n - 1) &&
			avl_aux(tree->right, tree->n + 1, upper_bound));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_aux(tree, INT_MIN, INT_MAX));
}
