#include "binary_trees.h"
/* Function declarations */
heap_t *last_order_lvl(heap_t *root, int index, int size);
heap_t *re_build(heap_t *root);

/**
* heap_extract - extracts the top value from the heap
* @root: double pointer to root node
*Return value if extracted else 0
*/
int heap_extract(heap_t **root)
{

	int tmp, s;
	heap_t *last;

	if (!root || !(*root))
		return (0);
	s = binary_tree_size(*root);
	last = last_order_lvl(*root, 0, s - 1);

	tmp = last->n;
	last->n = (*root)->n;
	(*root)->n = tmp;
	if (last->parent && last->parent->left == last)
		last->parent->left = NULL;
	if (last->parent && last->parent->right == last)
		last->parent->right = NULL;
	tmp = last->n;
	free(last);
	re_build(*root);
	return (tmp);
}

/**
* last_order_lvl - return last node in level order
* Return: heap_t
* @root: the root to get the last level order of
* @index: the current index of root
* @size: the total size of the tree
*/
heap_t *last_order_lvl(heap_t *root, int index, int size)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);
	if (index > size)
		return (NULL);
	if (index == size)
		return (root);
	left = last_order_lvl(root->left, 2 * index + 1, size);
	right = last_order_lvl(root->right, 2 * index + 2, size);
	if (left)
		return (left);
	if (right)
		return (right);
	return (NULL);
}
/**
* re_build - func that fixed the heap
* Return: the former head node
* @root: the root
*/
heap_t *re_build(heap_t *root)
{
	int tmp;

	if (!root)
		return (NULL);
	if (!(root->left) && !(root->right))
		return (NULL);
	if (root->left && !(root->right) && root->left->n > root->n)
	{
		tmp = root->left->n;
		root->left->n = root->n;
		root->n = tmp;
		re_build(root->left);
	}
	else if (root->right && !(root->left))
	{
		if (root->right->n > root->n)
		{
			tmp = root->right->n;
			root->right->n = root->n;
			root->n = tmp;
			re_build(root->right);
		}
	}
	else if (root->left->n > root->n && root->left->n > root->right->n)
	{
		tmp = root->left->n;
		root->left->n = root->n;
		root->n = tmp;
		re_build(root->left);
	}
	else if (root->right->n > root->n && root->right->n > root->left->n)
	{
		tmp = root->right->n;
		root->right->n = root->n;
		root->n = tmp;
		re_build(root->right);
	}
	return (NULL);
}
