#include "binary_trees.h"

/**
 * count_tree_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int count_tree_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_tree_nodes(root->left) +
		    count_tree_nodes(root->right));
}

/**
 * adjust_downward - Puts a node value in a correct position in the heap
 * @parent: Pointer to heap's node
 */
void adjust_downward(heap_t *parent)
{
	int tmp;
	heap_t *next_one = NULL;

	if (!parent)
		return;

	while (parent && parent->left)
	{
		next_one = parent->left;

		if (parent->right && parent->right->n > parent->left->n)
			next_one = parent->right;

		if (next_one->n > parent->n)
		{
			tmp = parent->n;
			parent->n = next_one->n;
			next_one->n = tmp;
		}

		parent = next_one;
	}
}

/**
 * find_parent - Finds the parent node for a certain node
 * @root: Pointer to heap's node
 * @value: Value of the current node
 * @tree: Value been searched
 *
 * Return: Pointer to heap's node
 */
heap_t *find_parent(heap_t *root, int value, int tree)
{
	heap_t *l = NULL, *r = NULL;

	if (!root || value > tree)
		return (NULL);

	if (value == tree)
		return (root);

	l = find_parent(root->left, value * 2 + 1, tree);
	if (l)
		return (l);

	r = find_parent(root->right, value * 2 + 2, tree);
	if (r)
		return (r);

	return (NULL);
}

/**
 * delete_last_node - Removes the last node of a heap
 * @root: Double pointer to heap's root node
 * @parent: Pointer to parent node from which to remove the last node
 */
void delete_last_node(heap_t **root, heap_t *parent)
{
	if (parent == *root && !parent->left)
	{
		free(*root);
		*root = NULL;

		return;
	}

	if (parent->right)
	{
		(*root)->n = parent->right->n;
		free(parent->right);
		parent->right = NULL;
	}
	else if (parent->left)
	{
		(*root)->n = parent->left->n;
		free(parent->left);
		parent->left = NULL;
	}

	adjust_downward(*root);
}

/**
 * heap_extract - Extracts the max value of a heap
 * @root: Double pointer to heap's root node
 *
 * Return: Heap's max value
 */
int heap_extract(heap_t **root)
{
	int nx, tree = 0, high = 0;
	heap_t *parent;

	if (!root || !(*root))
		return (0);

	high = (*root)->n;
	nx = count_tree_nodes(*root);

	tree = (nx - 2) / 2;
	parent = find_parent(*root, 0, tree);

	delete_last_node(root, parent);

	return (high);
}
