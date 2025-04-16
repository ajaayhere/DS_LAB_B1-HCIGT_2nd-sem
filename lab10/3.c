
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int findDepth(struct Node* root, int target) {
    int depth = 0;
    while (root != NULL) {
        if (target == root->data)
            {return depth;
            depth++;}
        else if (target < root->data)
            {root = root->left;
            depth++;}
        else
            {root = root->right;
        depth++;}
    }
    return -1; 
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int target = 40;
    int depth = findDepth(root, target);

    if (depth != -1)
        printf("Depth  %d is: %d\n", target, depth);
    else
        printf(" %d not found in the tree.\n", target);

    return 0;
}
