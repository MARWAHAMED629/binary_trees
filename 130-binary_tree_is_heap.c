#include "binary_trees.h"
int complete(const binary_tree_t *tree, int index, int nodes);
/**
* binary_tree_is_heap - deterines if the tree is a heap
* Return: 1 if it is a valid max binary heap, else 0
* @tree: pointer to the root node of the tree to check
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nds, idx = 0;

	if (!tree)
		return (0);

	nds = binary_tree_size(tree);
	if (complete(tree, idx, nds) == 0)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (1);
	if (tree->right == NULL)
		return (tree->n > tree->left->n);
	if (tree->n < tree->left->n)
		return (0);
	if (tree->n < tree->right->n)
		return (0);
	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
/**
* complete - tests  all completeness
* Return: 1 for complete else 0
* @tree: root node of the tree
* @index: An index the node should be at
* @nodes: the total number of nodes
*/
int complete(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (complete(tree->left, 2 * index + 1, nodes) &&
		complete(tree->right, 2 * index + 2, nodes));
}
/**
* binary_tree_size - returns size of the binary tree
* Return: size_t size of the tree
* @tree: pointer to root node of the tree to be measured
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
* complete_chk - checks if the current node can be in a  tree
* Return: the void
* @tree: root the node
* @h_leaf: has a leaf been hit
* @level: what tree level
*/
void complete_chk(const binary_tree_t *tree, int *h_leaf, size_t level)
{
	if (!tree)
	{
		if (*h_leaf == 0)
			*h_leaf = 1;
		return;
	}
	if (level == 0)
	{
		if (*h_leaf == 1)
		{
			*h_leaf = 2;
		}
	}
	else
	{
		complete_chk(tree->left, h_leaf, level - 1);
		complete_chk(tree->right, h_leaf, level - 1);
	}
}
/**
* binary_tree_height - finds the height of the binary tree
* Return: the height as a size_t
* @tree: the root node
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (!tree)
		return (0);
	if (!(tree->left) && !(tree->right))
		return (0);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_left > h_right)
		return (1 + h_left);
	return (1 + h_right);
}
