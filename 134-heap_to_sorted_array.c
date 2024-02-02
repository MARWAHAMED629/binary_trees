#include "binary_trees.h"

/**
 * tree_sz - measures the sum of the heights in a binary tree
 * @tree: the pointer to the root node of the tree.
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_sz(const binary_tree_t *tree)
{
	size_t ht_left = 0;
	size_t ht_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		ht_left = 1 + tree_sz(tree->left);

	if (tree->right)
		ht_right = 1 + tree_sz(tree->right);

	return (ht_left + ht_right);
}

/**
 * heap_to_sorted_array - function that converts a Binary Max Heap
 * to a sorted array of an  integers
 *
 * @heap: the pointer to the root node.
 * @size: address to store the size of the array.
 *
 * Return: pointer to array sorted.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int z, *b = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_sz(heap) + 1;

	b = malloc(sizeof(int) * (*size));

	if (!b)
		return (NULL);

	for (z = 0; heap; z++)
		b[z] = heap_extract(&heap);

	return (b);
}
