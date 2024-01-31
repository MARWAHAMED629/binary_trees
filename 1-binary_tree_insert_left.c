#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of the parent
 *
 * @pa: the pointer to the node to insert the left-child in.
 * @val: value to store in the new node.
 * Return: THE pointer to the created new node. NULL on itfailure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *pa, int val)
{
	binary_tree_t *pleft = NULL, *new_node = NULL;

	if (!pa)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = pa;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = val;

	pleft = pa->left;
	pa->left = new_node;

	if (pleft)
	{
		pleft->parent = new_node;
		new_node->left = pleft;
	}

	return (new_node);
}

