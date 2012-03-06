/* Binary Search Tree for integers
 * @Garg, Vineet
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0

/* structure for binary tree's node */
struct bst_node {
	int value; /* integer value b/w INT_MAX & INT_MIN*/
	struct bst_node *left_child;
	struct bst_node *right_child; /* children */
};

typedef struct bst_node bst_node;


bst_node* insert(struct bst_node *root, int value); /* insert a new node in tree root with given value into node */
void preorder_traversal(bst_node *root); /* traverse and print each node in pre order manner */
void inorder_traversal(bst_node *root); /* recursive in order traversal */
void postorder_traversal(bst_node *root); /* recursive post order traversal */
