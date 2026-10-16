#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Tree {
	struct Node *nodes;
	double depth;
	int count_nodes;
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

double get_depth(int nodes) {
	return log2(nodes);
}

struct Node *create_node(int data) {
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}


struct Tree *create_tree(int nodes) {
	if (nodes <= 0) {
		// in the future, create an empty tree
		printf("W: Invalid Nodes, created empty tree\n");
		return NULL;
	}

	int *data = create_data(nodes);
	if (data == NULL) {
		printf("E: Cannot create data\n");
		return NULL;
	}

	struct Tree *tree = (struct Tree *)malloc(sizeof(struct Tree));
	tree->nodes = (struct Node *)malloc(sizeof(struct Node) * nodes);
	
	tree->depth = get_depth(nodes);
	tree->count_nodes = nodes;

	for(int x = 0; x < nodes; ++x) {
		int current_data = data[x];
		struct Node *current_node = create_node(current_data);

		if (x <= 0) {
			tree->nodes[0] = *current_node;
		} else {
			struct Node current = *tree->nodes;
			
		}
	}

	show_all_data(data, nodes);

	return NULL;
}

int main() {

	create_tree(8);

	return 0;
}
