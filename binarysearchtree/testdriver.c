#include"bst.h"
#include<stdlib.h>
#include<limits.h>

int main() {
	bst_node *root;
	
	printf("Insertion initiating...\n");
	/* generate random number */
	int i;
	for(i=0; i<10; i++){
		int value = rand() % 100;
		printf("Inserting value: %d\n", value);
		root = insert(root, value);
	}

	printf("Insertion finished\n");

	printf("******************Pre Order Traversal*****************\n");
	preorder_traversal(root);
	printf("\n*******************************************************\n");

	printf("******************In Order Traversal*****************\n");
	inorder_traversal(root);
	printf("\n*******************************************************\n");

	printf("******************Post Order Traversal*****************\n");
	postorder_traversal(root);
	printf("\n*******************************************************\n");

}
