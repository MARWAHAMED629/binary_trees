#include "binary_trees.h"

/**
 * bst_insert - inserts a value in the Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the v
 * @value: the value to store in the node to be inserted
 * Return: the pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *n, *t_2;

	if (tree == NULL || *tree == NULL)
	{
		n = binary_tree_node(NULL, value);
		*tree = n;
		return (n);
	}

	t_2 = *tree;

	while (t_2 != NULL)
	{
		if (t_2->n == value)
			return (NULL);
		if (t_2->n > value)
		{
			if (t_2->left == NULL)
			{
				t_2->left = binary_tree_node(t_2, value);
				return (t_2->left);
			}
			t_2 = t_2->left;
		}
		if (t_2->n < value)
		{
			if (t_2->right == NULL)
			{
				t_2->right = binary_tree_node(t_2, value);
				return (t_2->right);
			}
			t_2 = t_2->right;
		}
	}
	return (NULL);
}
