#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data, choice = 1;

    while (choice) {
        printf("Enter data: ");
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add more nodes? (1/0): ");
        scanf("%d", &choice);
    }

    printf("Original list: ");
    printList(head);

    int swapData;
    printf("Enter the data of the node you want to swap with its next: ");
    scanf("%d", &swapData);

    struct Node* prev = NULL;
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == swapData) {
            struct Node* temp = current->next;
            current->next = temp->next;
            temp->next = current;
            
            if (prev == NULL) {
                head = temp;
            } else {
                prev->next = temp;
            }
            
            break;
        }
        prev = current;
        current = current->next;
    }

    printf("List after swapping: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
