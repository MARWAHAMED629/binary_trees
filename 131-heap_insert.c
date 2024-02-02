#include "binary_trees.h"
heap_t *heap_rep(heap_t *new, heap_t *parent);
heap_t *heap_fd(heap_t *root, size_t number);
size_t count(const binary_tree_t *tree);

/**
 * heap_insert -Inserting a new node into the heap
 *
 * @tree: double pointer to the root
 * @value: the value to store
 * Return: pointer to the created node
 */
heap_t *heap_insert(heap_t **tree, int value)
{
	size_t s;
	int do_swap = 1;
	heap_t *new, *parent;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	s = count(*tree);
	parent = heap_fd(*tree, (s - 1) / 2);
	new = binary_tree_node(parent, value);
	if (s % 2 == 1)
		parent->left = new;
	else
		parent->right = new;
	if (new == NULL)
		return (NULL);

	while (do_swap == 1 && parent != NULL)
	{
		if (parent->n >= new->n)
			do_swap = 0;
		else
		{
			new = heap_rep(new, parent);
			parent = new->parent;
		}
	}

	return (new);
}

/**
 * count -Calculate the number of nodes in the binary tree.
 *
 * @tree: pointer to the root
 * Return: size, otherwise 0
 */

size_t count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count(tree->left) + count(tree->right));
}

/**
 * heap_fd -Find the node number number in
 * the heap (in the order of the level).
 *
 * @root: pointer to the root
 * @number: index of the node to finds
 * Return: the pointer to the node
 */
heap_t *heap_fd(heap_t *root, size_t number)
{
	size_t p, dt;

	if (number == 0)
		return (root);

	p = (number - 1) / 2;
	dt = (number - 1) % 2;

	if (dt == 0)
		return (heap_fd(root, p)->left);
	return (heap_fd(root, p)->right);
}

/**
 * heap_rep -Switch the values of two nodes in the heap.
 * @new: pointer to the new node
 * @parent: pointer to the new parent
 * Return: parent
 */
heap_t *heap_rep(heap_t *new, heap_t *parent)
{
	int temp;

	temp = new->n;
	new->n = parent->n;
	parent->n = temp;
	return (parent);
}
