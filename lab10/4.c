//write  aprogram to find number of leaf and current node in binary search tree 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void count_leaf_and_internal_nodes(struct Node* root, int* leafCount, int* internalCount) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        (*leafCount)++;
    } else {
        (*internalCount)++;
    }

    count_leaf_and_internal_nodes(root->left, leafCount, internalCount);
    count_leaf_and_internal_nodes(root->right, leafCount, internalCount);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(12);
    root->right->right = newNode(18);

    int leafCount = 0;
    int internalCount = 0;

    count_leaf_and_internal_nodes(root, &leafCount, &internalCount);

    printf("Number of leaf nodes: %d\n", leafCount);
    printf("Number of internal nodes: %d\n", internalCount);

    return 0;
}







