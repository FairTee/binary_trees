#include "binary_trees.h"
#include<stdlib.h>
#include<string.h>
#define INIT_NODE {0, NULL, NULL, NULL}

/**
 * swap_nodes - swaps two nodes in binary tree
 * @x: first node
 * @y: second node
 * Return: pointer to root
 */
bst_t *swap_nodes(bst_t *x, bst_t *y)
{
	bst_t node_x = INIT_NODE;

	node_x.n = x->n;
	node_x.parent = x->parent;
	node_x.left = x->left;
	node_x.right = x->right;
	x->parent = y;
	x->left = y->left;
	x->right = y->right;
	if (y->left)
		y->left->parent = x;
	if (y->right)
		y->right->parent = x;

	y->parent = node_x.parent;
	if (node_x.parent)
	{
		if (x == node_x.parent->left)
			node_x.parent->left = y;
		else
			node_x.parent->right = y;
	}
	if (y == node_x.left)
	{
		y->left = x;
		y->right = node_x.right;
		if (node_x.right)
			node_x.right->parent = y;
	}
	else if (y == node_x.right)
	{
		y->right = x;
		y->left = node_x.left;
		if (node_x.left)
			node_x.left->parent = y;
	}
	while (y->parent)
		y = y->parent;
	return (y);
}

/**
 * num_to_base - converts number and base into string
 * @no: input number
 * @bs: input base
 * @lc: flag if hexa values need to be lowercase
 * Return: result string
 */
char *num_to_base(unsigned long int no, int bs, int lc)
{
	static char *r;
	static char buff[50];
	char *p;

	r = (lc)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buff[49];
	*p = 0;
	do {
		*--p = r[no % bs];
		no /= bs;
	} while (no);

	return (p);
}

/**
 * tree_size - measures the size of a binary tree
 * @tree: input binary tree
 * Return: number of descendant child nodes
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insert_node - helper function to insert node to correct location
 * @root: double pointer to root of max heap
 * @n: node to insert
 */
void insert_node(heap_t **root, heap_t *n)
{
	heap_t *temp;
	int s;
	unsigned int q;
	char *binx;
	char cw;

	temp = *root;
	s = tree_size(temp) + 1;
	binx = num_to_base(s, 2, 1);
	for (q = 1; q < strlen(binx); q++)
	{
		cw = binx[q];
		if (q == strlen(binx) - 1)
		{
			if (cw == '1')
			{
				n->parent = temp;
				temp->right = n;
				break;
			}
			else if (cw == '0')
			{
				n->parent = temp;
				temp->left = n;
				break;
			}
		}
		if (cw == '1')
			temp = temp->right;
		else if (cw == '0')
			temp = temp->left;
	}
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to root of tree
 * @value: input value
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *result;

	if (!root)
		return (NULL);
	new_node = calloc(1, sizeof(heap_t));
	new_node->n = value;
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	insert_node(root, new_node);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		result = swap_nodes(new_node->parent, new_node);
		if (result)
			*root = result;
	}
	return (new_node);
}
