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
		printf("W: Invalid Nodes\n");
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

		struct Node *new_node = create_node(current_data);
		if (x <= 0) {
			tree->nodes[0] = *new_node;
		} else {
			int y = 1;
			struct Node *current_node = &tree->nodes[0];
			while(y == 1) {
				if (new_node->data < current_node->data) {
					if (current_node->left == NULL) {
						current_node->left = new_node;
						if (x >= 2) {
							tree->nodes[x - 1] = *current_node;
						}
						y = 0;
					} else {
						current_node = current_node->left;
					}
				} else if (new_node->data > current_node->data) {
					if (current_node->right == NULL) {
						current_node->right = new_node;
						if (x >= 2) {
							tree->nodes[x - 1] = *current_node;
						}
						y = 0;
					} else {
						current_node = current_node->right;
					}
				}

			}

			tree->nodes[x] = *new_node;
		}
	}

	return tree;
}

int main() {

	int nodes;
	printf("Enter the numbers of nodes: \n");
	int input = scanf("%d", &nodes);

	if (input == EOF) {
		printf("Invalid input\n");
		return -1;
	}

	struct Tree *tree = create_tree(nodes);
	
	printf("Depth: %.0f\n", tree->depth);
	printf("Nodes: %d\n", tree->count_nodes);

	for(int x = 0; x < nodes; ++x) {
		printf("Node data -> %d\n", tree->nodes[x].data);
		printf("Node left -> %p\n", tree->nodes[x].left);
		printf("Node right -> %p\n", tree->nodes[x].right);
		
		printf("=======================================\n");
	}

	return 0;
}
