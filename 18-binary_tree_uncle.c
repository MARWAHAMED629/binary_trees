#include "binary_trees.h"

/**
 * search_uncle - the binary tree
 * @node: the node
 * Return: the uncle
 */
binary_tree_t *search_uncle(binary_tree_t *node)
{
	binary_tree_t *gr_pa = NULL;

	if (!node || !(node->parent))
		return (NULL);
gr_pa = node->parent;
	/* check the left or the right uncle */
	if (gr_pa->left && (gr_pa->left != node))
		return (gr_pa->left);
	else if (gr_pa->right && (gr_pa->right != node))
		return (gr_pa->right);
	return (NULL);
}

/**
 * binary_tree_uncle - the binary tree
 * @node: the node
 * Return: the uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !(node->parent))
		return (NULL);
	return (search_uncle(node->parent));
}
