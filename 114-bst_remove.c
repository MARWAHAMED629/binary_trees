#include "binary_trees.h"
/**
 * min_found - Finds the minimum root
 * @root: the pointer to A tree
 * Return: the min number
 */

bst_t *min_found(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree.
 *
 * @root: pointer to the root node of the binary tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *p;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			p = root->parent;
			root = root->right;
			root->parent = p;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			p = root->parent;
			root = root->left;
			root->parent = p;
			free(tmp);
		}
		else
		{
			tmp = min_found(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
