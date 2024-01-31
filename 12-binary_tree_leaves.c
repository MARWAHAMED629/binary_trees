#include "binary_trees.h"

/**
 * binary_tree_leaves - this func counts the leaves in a binary tree
 *
 * @tree: If the tree is NULL, the function must return 0
 * Return: A NULL pointer is not a leaf
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t c_leaves = 0;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);

	c_leaves += binary_tree_leaves(tree->left);
	c_leaves += binary_tree_leaves(tree->right);

	return (c_leaves);
}
