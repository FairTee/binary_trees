#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 *
 * @tree: tree root
 * Return: size of the tree or 0 if tree is NULL;
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * is_complete_tree - checks if tree is complete
 *
 * @tree: pointer to the tree root
 * @x: node index
 * @node_num: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int is_complete_tree(const binary_tree_t *tree, int x, int node_num)
{
	if (tree == NULL)
		return (1);

	if (x >= node_num)
		return (0);

	return (is_complete_tree(tree->left, (2 * x) + 1, node_num) &&
			is_complete_tree(tree->right, (2 * x) + 2, node_num));
}

/**
 * bin_tree_completed - calls to is_complete_tree function
 *
 * @root: tree root
 * Return: 1 if tree is complete, 0 otherwise
 */
int bin_tree_completed(const binary_tree_t *root)
{
	size_t node_num;

	if (root == NULL)
		return (0);

	node_num = tree_size(root);

	return (is_complete_tree(root, 0, node_num));
}

/**
 * has_greater_parent - if parent has a greater value than its childs
 *
 * @tree: pointer to the node
 * Return: 1 if parent has a greater value, 0 otherwise
 */
int has_greater_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (has_greater_parent(tree->left) && has_greater_parent(tree->right));
}

/**
 * binary_tree_is_heap - If an input tree is a Max Binary Heap
 *
 * @tree: pointer to the root of the tree
 * Return: 1 Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!bin_tree_completed(tree))
		return (0);

	return (has_greater_parent(tree->left) && has_greater_parent(tree->right));
}
