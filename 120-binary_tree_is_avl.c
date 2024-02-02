#include "binary_trees.h"

/**
 * Calcu_height - THE aux level.
 *
 * @tree: pointer to root
 * Return: integer with level
 */

int Calcu_height(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	height_l = Calcu_height(tree->left);
	height_r = Calcu_height(tree->right);
	if (height_l > height_r)
		return (height_l + 1);
	else
		return (height_r + 1);
}


/**
 * binary_tree_balance - Calculation of the balance factor for a
 * node in a b * in a binary tree (the difference
 *  between the height of the left and left
 *
 * @tree: pointer to root
 * Return: integer with factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (Calcu_height(tree->left) - Calcu_height(tree->right));
}

/**
 * bavl - check if the binary tree is a valid AVL tree.
 *
 * @tree: the pointer to root
 * @mini: the minimum value
 * @maxi: the maximum value
 * Return: 1 if is AVL, 0 otherwise
 */

int bavl(const binary_tree_t *tree, int mini, int maxi)
{
	int bal_left, bal_right, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > maxi || tree->n < mini)
		return (0);
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	bal_left = bavl(tree->left, mini, tree->n - 1);
	bal_right = bavl(tree->right, tree->n + 1, maxi);
	if (bal_left == 1 && bal_right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));

}
