#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

int *create_data(int nodes) {
	int *data = (int *)malloc(sizeof(int) * nodes);
	if (data == NULL) return NULL;

	int counter = 0;
	while(counter < nodes) {
		data[counter] = rand();
		counter++;
	}
	return data;
}

void show_all_data(int *data, int iterator) {
	for(int x = 0; x < iterator; ++x) {
		printf("%d\n", data[x]);
	}
}

struct Tree *create_tree(int nodes) {
	if (nodes <= 0) {
		printf("W: Invalid Nodes, create empty tree\n");
		return NULL;
	}

	int *data = create_data(nodes);
	if (data == NULL) {
		printf("E: Cannot create data\n");
		return NULL;
	}

	int counter = 0;
	for(int x = 0; x < nodes; ++x) {
	}

	show_all_data(data, nodes);

	return NULL;
}

struct Node *create_node(int data) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main() {

	create_tree(8);

	return 0;
}
