#include "binary_trees.h"

/**
 * binary_tree_height_balance - it measures the balance factor of a binary tree
 * @tree: THE pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: THE height
 * If tree is NULL, return 0
 */

size_t binary_tree_height_bal(const binary_tree_t *tree)
{
	size_t h_l = 0, h_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_l = 1 + binary_tree_height_bal(tree->left);
	if (tree->right)
		h_r = 1 + binary_tree_height_bal(tree->right);

	if (h_l > h_r)
		return (h_l);
	return (h_r);
}

/**
 * binary_tree_balance - This Func measures the balance factor of a binary tree
 *
 * @tree: The pointer to the root node of the tree
 * Return: The balance factor
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);
	if (tree->left)
		height_l = 1 + binary_tree_height_bal(tree->left);
	if (tree->right)
		height_r = 1 + binary_tree_height_bal(tree->right);
	return (height_l - height_r);
}
