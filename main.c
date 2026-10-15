#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main() {
	struct Node *root = create_node(1); // 0
	root->left = create_node(2); // 1
	root->right = create_node(3); // 1

	root->left->left = create_node(4); // 2
	root->left->right = create_node(5); // 2

	root->right->left = create_node(6); // 3
	root->right->right = create_node(7); // 3


	return 0;
}
