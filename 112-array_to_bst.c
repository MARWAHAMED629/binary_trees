#include "binary_trees.h"

/**
 * array_to_bst - func that builds a Binary Search Tree from an array
 *
 * @array: pointer to the 1st element of an array to be converted
 * @size: the number of  an element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t len;
	bst_t *tree = NULL;

	for (len = 0; len < size; len++)
		bst_insert(&tree, array[len]);

	return (tree);
}
