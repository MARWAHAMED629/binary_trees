#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height- measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height(tree->left);

	if (tree->right)
		height_r = 1 + binary_tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * _tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t _tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + _tree_size(tree->left);

	if (tree->right)
		height_r = 1 + _tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal.
 * @tree: pointer to the root node of the tree to traverse
 * @node: it will be last note in traverse
 * @h: the height of tree
 *
 * Return: No Thing
 */
void _preorder(heap_t *tree, heap_t **node, size_t h)
{
	if (!tree)
		return;

	if (!h)
		*node = tree;
	h--;

	_preorder(tree->left, node, h);
	_preorder(tree->right, node, h);
}

/**
 * heapi_fy - heapifies the  max binary heap
 * @root: the pointer to binary heap
 */
void heapi_fy(heap_t *root)
{
	int v;
	heap_t *temp1, *temp2;

	if (!root)
		return;

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		v = temp1->n;
		temp1->n = temp2->n;
		temp2->n = v;
		temp1 = temp2;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *nd;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &nd, binary_tree_height(heap_r));

	heap_r->n = nd->n;
	if (nd->parent->right)
		nd->parent->right = NULL;
	else
		nd->parent->left = NULL;
	free(nd);
	heapi_fy(heap_r);
	*root = heap_r;
	return (value);
}
