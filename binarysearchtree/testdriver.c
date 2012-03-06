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
		if( insert(&root, value) == FALSE)
			exit(0);
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

	/* Search for a node */
	/*if( search(root, 92) != NULL)
		printf("FOUND \n");
	else
		printf("NOT FOUND\n");
	
	fflush(stdout); */
	(search(root, 93) == NULL)? (printf("Value 93 isn't found!\n")): (printf("Value 93 found in tree \n"));
	(search(root, 192) == NULL)? (printf("Value 192 isn't found!\n")): (printf("Value 92 found in tree \n"));

	/* Delete any node */
	(delete_node(&root, 93) == TRUE)? (printf("Deleted 93 node successfully\n")): (printf("Deletion Failure !\n"));

	(delete_node(&root, 92) == TRUE)? (printf("Deleted 92 node successfully\n")): (printf("Deletion Failure !\n"));
	/*** Print the tree */

	printf("******************In Order Traversal*****************\n");
	inorder_traversal(root);
	printf("\n*******************************************************\n");

	//(delete_node(&root, 93) == TRUE)? (printf("Deleted 92 node successfully\n")): (printf("Deletion Failure !\n"));

	/*printf("******************In Order Traversal*****************\n");
	inorder_traversal(root);
	printf("\n*******************************************************\n"); */
}
