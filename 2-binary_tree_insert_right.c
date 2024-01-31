#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 * right-child of the another Parenr node
 *
 * @par: the pointer to the node to insert the right-child in
 * @val: the alue to store in the new node
 * Return: a pointer to the created node,
 *	or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *par, int val)
{
	binary_tree_t *new = NULL;

	if (!par)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = val;
	new->left = NULL;

	if (par->right == NULL)
	{
		new->parent = par;
		new->right = NULL;
		par->right = new;
	}
	else
	{
		new->parent = par;
		new->right = par->right;
		par->right = new;
		new->right->parent = new;
	}
	return (new);
}
