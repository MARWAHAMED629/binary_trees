#include "binary_trees.h"

/**
 * binary_tree_nodes - This Funcs counts the
 *  nodes with at least 1 child in a binary tree
 *
 * @tree: THE pointer to the root node of the tree to count the number of nodes
 * Return: If the tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t c = 0;

	if (!tree)
		return (0);

	if (tree->left || tree->right)
		c = 1;

	c += binary_tree_nodes(tree->left);
	c += binary_tree_nodes(tree->right);

	return (c);
}
