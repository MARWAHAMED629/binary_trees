#include "binary_trees.h"

/**
 * binary_tree_depth - it measures the depth of a node in a binary tree
 *
 * @tree: the pointer to the node to measure the depth
 * Return: 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dep = 0;

	if (!tree)
		return (0);
	if (tree->parent)
		dep = 1 + binary_tree_depth(tree->parent);
	return (dep);
}
