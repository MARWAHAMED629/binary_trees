#include "binary_trees.h"

/**
 * binary_trees_ancestor - it Finds the lowes
 * @first:the Pointer
 * @second:the Pointer
 *
 * Return:the Pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *first_an, *second_an;

	for (first_an = first; first_an; first_an = first_an->parent)
		for (second_an = second; second_an; second_an = second_an->parent)
			if (first_an == second_an)
				return ((binary_tree_t *)first_an);
	return (NULL);
}
