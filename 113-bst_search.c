#include "binary_trees.h"

/**
 * bst_search - checks for a value in the Binary Search Tree
 *
 * @tree: pointer to the root node of the BST to search
 * @value: value to search.
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((binary_tree_t *) tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
