#include "binary_trees.h"

/**
 * array_to_heap - builds the Max Binary Heap tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root nodecreated Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t z;
	heap_t *rt = NULL;

	if (!array)
		return (NULL);

	rt = heap_insert(&rt, array[0]);
	for (z = 1; z < size; z++)
		heap_insert(&rt, array[z]);

	return (rt);
}
