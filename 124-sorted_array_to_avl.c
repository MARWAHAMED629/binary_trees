#include "binary_trees.h"

/**
* sorted_array_to_avl - makes an avl tree from sorted array
* Return: pointer to root node of avl tree
* @array: sorted an array of  the ints to make into tree
* @size: how many ints are in the size
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *n_node;
	unsigned int midd;

	if (!array || size == 0)
		return (NULL);
	midd = size / 2 - (1 - size % 2);

	n_node = binary_tree_node(NULL, array[midd]);
	if (!n_node)
		return (NULL);

	n_node->left = sorted_array_to_avl(array, midd);
	if (n_node->left)
		n_node->left->parent = n_node;
	else if (midd > 0)
		return (NULL);
	n_node->right = sorted_array_to_avl(&array[midd + 1], size / 2);
	if (n_node->right)
		n_node->right->parent = n_node;
	else if (size / 2 > 0)
		return (NULL);

	return (n_node);
}
