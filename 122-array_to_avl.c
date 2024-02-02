#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of an element in the array
 * Return: Pointer to the root
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x;
	avl_t *r = NULL;

	if (!array || size == 0)
		return (NULL);

	r = avl_insert(&r, array[0]);
	for (x = 1; x < size; x++)
		avl_insert(&r, array[x]);

	return (r);
}
