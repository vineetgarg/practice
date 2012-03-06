/* binary search tree implementation */
#include"bst.h"

/* insert new node with given value into bst root
 and return the new tree
 */
bst_node* insert(struct bst_node *root, int value){

	/* create new node */
	bst_node *new_bst_node = (bst_node*)malloc(sizeof(bst_node));
	assert( new_bst_node != NULL);
	new_bst_node->value = value;

	if( root == NULL) /* if tree is empty */
		root=new_bst_node;
	else{ /* if tree isn't empty */
		bst_node *temp_node = root;
		bst_node *save_parent = NULL;
		while( temp_node != NULL){
			save_parent = temp_node; /* save the parent node */
			if( value <= temp_node->value)
				temp_node = temp_node->left_child;
			else
				temp_node = temp_node->right_child;
		}

		if( value <= save_parent->value)
			save_parent->left_child = new_bst_node;
		else
			save_parent->right_child = new_bst_node;
	}

	return root;
}

/* Pre order traversal recursively */
void preorder_traversal(bst_node *root){
	if(root == NULL)
		return;
	printf("\t%d", root->value);
	preorder_traversal(root->left_child);
	preorder_traversal(root->right_child);
}

/* In order traversal recursively */
void inorder_traversal(bst_node *root){
	if(root->left_child != NULL)
		inorder_traversal(root->left_child);

	printf("\t%d", root->value);
	if(root->right_child != NULL)
		inorder_traversal(root->right_child);
}

/* Post order traversal recursively */
void postorder_traversal(bst_node *root){
	if(root->left_child != NULL)
		postorder_traversal(root->left_child);

	if(root->right_child != NULL)
		postorder_traversal(root->right_child);

	printf("\t%d", root->value);
}
