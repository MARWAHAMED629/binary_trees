#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotation on a tree
 * @tree: A pointer to the root node.
 *
 * Return: the Pointer
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chi, *parent = tree;

	if (!tree)
		return (NULL);

	chi = parent->left;
	if (!chi)
		return (tree);

	if (chi->right)
		chi->right->parent = parent;

	parent->left = chi->right;
	chi->right = parent;
	chi->parent = parent->parent;
	parent->parent = chi;

	if (chi->parent && chi->parent->left == parent)
		chi->parent->left = chi;
	else if (chi->parent)
		chi->parent->right = chi;

	return (chi);
}
