#include "binary_trees.h"

/**
 * binary_tree_inorder:it performs an in-order traversal of a binary tree,
 * calling a provided function on the value of each node.
 * @tree: the pointer to the root node of the tree to traverse
 * @func: the pointer to a function to call for each node.
 * The value in the node must be passed as the parameter to this function.
 * If tree or func is NULL, do nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
