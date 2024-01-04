#include "binary_trees.h"

/**
 * let_balance - Measures balance factor of an AVL tree and performs rotations.
 * @tree: Pointer to the root node of the tree.
 */
void let_balance(avl_t **tree)
{
	int b;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	let_balance(&(*tree)->left);
	let_balance(&(*tree)->right);

	b = binary_tree_balance((const binary_tree_t *)*tree);

	if (b > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * replace - Finds the next replacement
 * @tree: Pointer to the tree to check.
 * Return: The minimum value of this tree.
 */
int replace(bst_t *tree)
{
	int sit = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		sit = replace(tree->left);
		if (sit == 0)
		{
			return (tree->n);
		}
		return (sit);
	}
}

/**
 * remove_value_node - Removes a node depending on its children.
 * @root: Node to remove.
 * Return: 0 if it has no children or another value if it has.
 */
int remove_value_node(bst_t *root)
{
	int root_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		root_value = replace(root->right);
		root->n = root_value;
		return (root_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 * Return: The tree changed.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int kind = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		kind = remove_value_node(root);
		if (kind != 0)
			bst_remove(root->right, kind);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 * Return: The tree changed.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *a = (avl_t *) bst_remove((bst_t *) root, value);

	if (a == NULL)
		return (NULL);

	let_balance(&a);
	return (a);
}
