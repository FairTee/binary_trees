#include "binary_trees.h"
#include <stdlib.h>

#define INIT_NODE {0, NULL, NULL, NULL}
#define HEX_DIGITS "0123456789ABCDEF"
#define NODE_SETUP_BLOCK { \
	temp = *root; \
	s = binary_tree_size(*root); \
	binx = &buffx[49]; \
	*binx = 0; \
}

#define NODE_FREE_BLOCK { \
	r = temp->n; \
	free(temp); \
	*root = NULL; \
}

#define TOP_SWAP_BLOCK { \
	top = *root; \
	top = swap_top(top, temp); \
	r = top->n; \
	free(top); \
	*root = temp; \
	temp = fix_position(temp); \
	*root = temp; \
}

#define CONVERT_LOOP_BLOCK { \
	*--binx = HEX_DIGITS[s % 2]; \
	s /= 2; \
}

/**
 * node_swap - swaps two nodes in a binary tree
 * @x: first node
 * @y: second node
 * Return: pointer to root
 */
bst_t *node_swap(bst_t *x, bst_t *y)
{
	bst_t x_c = INIT_NODE;

	x_c.n = x->n;
	x_c.parent = x->parent;
	x_c.left = x->left;
	x_c.right = x->right;
	x->parent = y;
	x->left = y->left;
	x->right = y->right;
	if (y->left)
		y->left->parent = x;
	if (y->right)
		y->right->parent = x;

	y->parent = x_c.parent;
	if (x_c.parent)
	{
		if (x == x_c.parent->left)
			x_c.parent->left = y;
		else
			x_c.parent->right = y;
	}
	if (y == x_c.left)
	{
		y->left = x;
		y->right = x_c.right;
		if (x_c.right)
			x_c.right->parent = y;
	}
	else if (y == x_c.right)
	{
		y->right = x;
		y->left = x_c.left;
		if (x_c.left)
			x_c.left->parent = y;
	}
	while (y->parent)
		y = y->parent;
	return (y);
}

/**
 * swap_top - helper func to swap top and node
 * @top: pointer to top
 * @node: pointer to node
 * Return: pointer to severed top of tree
 */
heap_t *swap_top(heap_t *top, heap_t *node)
{
	if (node->parent->left == node)
	{
		node->parent->left = NULL;
	} else
		node->parent->right = NULL;
	node->parent = NULL;
	node->left = top->left;
	node->right = top->right;
	if (top->left)
		top->left->parent = node;
	if (top->right)
		top->right->parent = node;
	return (top);
}

/**
 * fix_position - percolate top into correct position
 * @node: pointer to top
 * Return: pointer to top of tree
 */
heap_t *fix_position(heap_t *node)
{
	int high;
	heap_t *new = node;

	if (!node)
		return (NULL);
	high = node->n;
	if (node->left)
		high = MAX(node->left->n, high);
	if (node->right)
		high = MAX(node->right->n, high);
	if (node->left && high == node->left->n)
		new = node->left;
	else if (node->right && high == node->right->n)
		new = node->right;
	if (new != node)
	{
		node_swap(node, new);
		fix_position(node);
	}
	return (new);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to root of tree
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	size_t s, q;
	char *binx, c_w, buffx[50];
	int r;
	heap_t *temp, *top;

	if (!root || !*root)
		return (0);
	NODE_SETUP_BLOCK;
	if (s == 1)
	{
		NODE_FREE_BLOCK;
		return (r);
	}
	do {
		CONVERT_LOOP_BLOCK;
	} while (s);

	for (q = 1; q < strlen(binx); q++)
	{
		c_w = binx[q];
		if (q == strlen(binx) - 1)
		{
			if (c_w == '1')
			{
				temp = temp->right;
				break;
			}
			else if (c_w == '0')
			{
				temp = temp->left;
				break;
			}
		}
		if (c_w == '1')
			temp = temp->right;
		else if (c_w == '0')
			temp = temp->left;
	}
	TOP_SWAP_BLOCK;
	return (r);
}
