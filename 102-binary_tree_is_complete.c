#include "binary_trees.h"

/**
 * count_nds - count_nodes Counts ths inside a tree.
 * @root:  the node
 *
 * Return: the Number odes
 */

int count_nds(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nds(root->left) + count_nds(root->right));
}


/**
 * is_complete - it Checks if the tree is complete
 * @root: Pointer to the tree's root
 * @index: An Index of the node been evaluated
 * @n: the number of trees nod
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */

int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, index * 2 + 1, n));

	return (is_complete(root->left, index * 2 + 1, n) &&
		is_complete(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - it check for bt complete
 * @tree: Pointer to the root
 *
 * Return: 1 if is complete 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int n;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	n = count_nds(root);

	return (is_complete(root, 0, n));
}
