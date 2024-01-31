#include "binary_trees.h"
/**
 * binary_tree_node - it create a binary tree node
 *
 * @parent: The pointer to the parent node
 * @value: value to put in the node
 * Return: the new node
 *	or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}
