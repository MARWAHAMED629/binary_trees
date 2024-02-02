#include "binary_trees.h"

/**
 * avl_insert_full - Insert a new value into the AVL tree repeatedly,
 *
 * @tree: the pointer to the root
 * @parent: the parent of node
 * @value: the value
 * Return: pointer to the new_node node
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_nde;

	if (tree == NULL)
	{
		new_nde = binary_tree_node(parent, value);
		if (parent->n > new_nde->n)
			parent->left = new_nde;
		else
			parent->right = new_nde;
		return (new_nde);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}


/**
 * value_balance - Rebalance the AVL tree after
 *  inserting a new value if necessary.
 *
 * @root: pointer to the root of the tree
 * @tree: pointer to the node to be rebalanced
 * @value: inserted value
 * Return: 0
 */

void value_balance(avl_t **root, avl_t *tree, int value)
{
	int new_b;

	new_b = binary_tree_balance(tree);
	if (new_b > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_b < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}


/**
 * avl_insert - Drag a new value into the AVL tree,
 *  ensuring the preservation of AVL properties
 *
 * @tree: double pointer to root
 * @value: the value
 * Return: pointer to the new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *n_node, *pred;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		n_node = binary_tree_node(NULL, value);
		*tree = n_node;
		return (n_node);
	}
	n_node = avl_insert_full(*tree, NULL, value);

	if (n_node == NULL)
		return (NULL);

	pred = n_node->parent;

	while (pred != NULL)
	{
		value_balance(tree, pred, value);
		pred = pred->parent;
	}

	return (n_node);
}
