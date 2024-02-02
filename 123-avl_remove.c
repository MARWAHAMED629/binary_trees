#include "binary_trees.h"
bst_t *remove_one_child(bst_t *todel);
/**
* avl_remove - removes a node value from the tree
* Return: pointer to new root node of the tree
* @root: the root of the tree to remove from
* @value: the value to check for/remove
*/
bst_t *avl_remove(bst_t *root, int value)
{
	bst_t *todel, *successor;
	int balance;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
/*	else root-> must be value*/
	else
	{
		todel = root;
		if (!(todel->right) && !(todel->left))
		{
			root = remove_one_child(root);
			return (root);
		}
		else if (todel->right && todel->left)
		{
			successor = i_success(todel->right);
			root->n = successor->n;
			remove_one_child(successor);
		}
		else
		{
			root = remove_one_child(root);

		}
	}

	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	if (root)
		return (root);
	return (NULL);
}
/**
* remove_one_child - removes node with one child
* Return: the node that took it's place
* @todel: the node to remove
*/
bst_t *remove_one_child(bst_t *todel)
{
	bst_t *replacement = NULL;

	if (!todel)
		return (NULL);
	if (todel->right)
	{
		replacement = todel->right;
		todel->right->parent = todel->parent;
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = todel->right;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = todel->right;
	}
	else if (todel->left)
	{
		replacement = todel->left;
		todel->left->parent = todel->parent;
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = todel->left;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = todel->left;
	}
	else
	{
		if (todel->parent && todel->parent->left == todel)
			todel->parent->left = NULL;
		if (todel->parent && todel->parent->right == todel)
			todel->parent->right = NULL;
	}
	free(todel);
	return (replacement);
}
/**
* i_success - finds next in order successor
* Return: pointer to the successor
* @root: the root node to check from
*/
bst_t *i_success(bst_t *root)
{
	if (!root)
		return (NULL);
	if (!(root->left))
		return (root);
	return (i_success(root->left));
}
/**
* bst_search - searches ths bst
* Return: return pointer to node with valu
* @tree: pointer to root node
* @value: value to search for
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
