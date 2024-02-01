#include "binary_trees.h"

/**
 * isBST_h - Compare the node in order to check if a given
 *
 * @tree: the pointer to the root node of the tree to check
 * @mini: the minimum value
 * @maxi: the maximum value
 *
 * Return: 1 if success, 0 otherwise
 */
int isBST_h(const binary_tree_t *tree, int mini, int maxi)
{
	if (tree == NULL)
		return (1);

	if (tree->n < mini || tree->n > maxi)
		return (0);

	return (
		isBST_h(tree->left, mini, tree->n - 1) &&
		isBST_h(tree->right, tree->n + 1, maxi)
	);
}

/**
 * binary_tree_is_bst - it checks if a binary tree,
 * is a valid Binary Search tree
 *
 * @tree: the pointer to the root node of the tree to check
 * Return: 1 if success, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBST_h(tree, INT_MIN, INT_MAX));
}

