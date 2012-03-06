/* binary search tree implementation */
#include"bst.h"

/* insert new node with given value into bst root
 and return the new tree
 */
short int insert(struct bst_node **root, int value){

	/* create new node */
	bst_node *new_bst_node = (bst_node*)malloc(sizeof(bst_node));
	assert( new_bst_node != NULL);
	new_bst_node->value = value;

	if( *root == NULL) /* if tree is empty */
		*root=new_bst_node;
	else{ /* if tree isn't empty */
		bst_node *temp_node = *root;
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
	return TRUE;
	//return root;
}

/* delete the node with given value in given tree (root)
 * It returns TRUE on success
 */
short int delete_node(bst_node **root, int value){ /* delete the value in given root node */
	if( *root == NULL)
		return FALSE;

	bst_node *temp_node = *root;
	bst_node *save_parent = NULL;

	short int left_child_flag; /* this determine if the given node is left child or not. 1 means it is otherwise no */ 

	/* first find the node to be deleted */
	while( temp_node != NULL && temp_node->value != value){
		save_parent = temp_node;
		if( value > temp_node->value){
			temp_node = temp_node->right_child;
			left_child_flag = 0; /* it is right child */
		}
		else{
			temp_node = temp_node->left_child;
			left_child_flag = 1;
		}
	}

	/* if we didn't find the node */
	if( temp_node == NULL)
		return FALSE;

	/* if we found the node */
	/* if node do not have any children simply delete it */
	if( temp_node->left_child == NULL && temp_node->right_child == NULL){
		if(left_child_flag) /* if it is left child of its parent */	
			save_parent->left_child = NULL;
		else
			save_parent->right_child = NULL;

		free(temp_node); /* free the memory */

		return TRUE;
	}

	/* if node have only one child */
	if( (temp_node->left_child == NULL && temp_node->right_child != NULL) ){ /* node has right child */
		if(left_child_flag) /* if it is left child of its parent */
			save_parent->left_child = temp_node->right_child;
		else
			save_parent->right_child = temp_node->right_child;

		free(temp_node);
		return TRUE;
	}
	
	/*node has left child only */
	if((temp_node->left_child != NULL && temp_node->right_child == NULL)){
		if(left_child_flag) /* if it is left child of its parent */
			save_parent->left_child = temp_node->left_child;
		else
			save_parent->right_child = temp_node->left_child;

		free(temp_node);
		return TRUE;
	}

	/*  node has both children */
	printf("SEARCH - FELL OUT \n");


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

/* Search 
 * Note that if there are more than one node with the same value
 * it will return the first node encountered in path
*/
bst_node* search(bst_node *root, int value){
	while( root != NULL && root->value != value){
		if( value > root->value)
			root = root->right_child;
		else
			root = root->left_child;
	}

	if(root == NULL)
		return NULL;
	else 
		return root;
}
