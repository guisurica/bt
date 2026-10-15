#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *create_node(int data) {
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int print_node(struct Node *pNode) {
	if (pNode == NULL) {
		printf("Error: Printing null node\n");
		printf("TS: Pass a valid node to print\n");
		return -1;
	}
	
	printf("%d\n", pNode->data);

	return 0;
}

int main() {
	struct Node *node = create_node(1);
	if (print_node(node) == -1) {
		return -1;
	}


	return 0;
}
