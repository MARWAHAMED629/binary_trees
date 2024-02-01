#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a left rotation the binary tree.
 * @tree: the Pointer root
 *
 * Return: the Pointer  root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chi, *parent = tree;

	if (!tree)
		return (NULL);

	chi = parent->right;
	if (!chi)
		return (tree);

	if (chi->left)
		chi->left->parent = parent;

	parent->right = chi->left;
	chi->left = parent;
	chi->parent = parent->parent;
	parent->parent = chi;

	if (chi->parent && chi->parent->left == parent)
		chi->parent->left = chi;
	else if (chi->parent)
		chi->parent->right = chi;

	return (chi);
}
