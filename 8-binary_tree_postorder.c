#include "binary_trees.h"

/**
 * binary_tree_postorder - Print through binary tree using post-order traversal
 * @tree: the pointer to the root node of the tree to traverse
 * @func: the pointer to a function to call for each node.
 * The value in  node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!(tree) || !(func))
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
