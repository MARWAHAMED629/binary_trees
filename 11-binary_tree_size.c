#include "binary_trees.h"

/**
 * binary_tree_size - it measures the size of the binary tree
 *
 * @tree: The pointer to the root node of the tree to measure the size
 * Return: size or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t z = 1;

	if (!tree)
		return (0);

	z += binary_tree_size(tree->left);
	z += binary_tree_size(tree->right);

	return (z);
}
