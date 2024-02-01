#include "binary_trees.h"

/**
 * binary_tree_height_aux -  Function that measures
 * the height of the binary tree
 * @tree: the point of tree
 * Return: the height.
 */
size_t	binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (!tree)
		return (0);
	if (tree->left)
		height_l = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		height_r = 1 + binary_tree_height_aux(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * print_level_order - print each element in a level_order
 * @tree: The pointer root noode
 * @level: A level of the tree
 * @func: The pointer to a  node
 * Return: The void
 */
void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - function that goes through a
 * binary tree using level-order traversal.
 * @tree: the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: the void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = 0;
	int lenght = 1;

	if (!tree || !func)
		return;

	h = binary_tree_height_aux(tree) + 1;

	while (lenght <= h)
	{
		print_level_order(tree, lenght, func);
		lenght++;
	}
}
